/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:34:16 by rusty             #+#    #+#             */
/*   Updated: 2022/03/02 15:38:04 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **paths, char *cmd)
{
	int		i;
	char	*name;

	i = -1;
	if (!access(cmd, F_OK))
		return (cmd);
	while (paths[++i])
	{
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
			name = ft_multi_join(3, paths[i], "/", cmd);
		else
			name = ft_strjoin(paths[i], cmd);
		if (!access(name, F_OK))
			return (name);
	}
	return (cmd);
}

char	*add_pwd(char *pwd, char *cmd)
{
	if (!pwd)
		return (cmd);
	if (pwd[ft_strlen(pwd) - 1] != '/')
	{
		if (cmd[0] != '/')
			return (ft_multi_join(3, pwd, "/", cmd));
		else
			return (ft_strjoin(pwd, cmd));
	}
	else
	{
		if (cmd[0] != '/')
			return (ft_strjoin(pwd, cmd));
		else
			return (ft_strjoin(pwd, cmd + 1));
	}
	return (NULL); // will newer get here 
}

void	close_all(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->cmds_count)
	{
		if (shell->cmds_arr[i]->fd[0] != 0)
			close(shell->cmds_arr[i]->fd[0]);
		if (shell->cmds_arr[i]->fd[1] != 1)
			close(shell->cmds_arr[i]->fd[1]);
	}
}

void	exec_cmd(t_cmd *cmd, t_shell *shell)
{
	char	*full_cmd;

	if (cmd->cmd_name[0] == '.')
		full_cmd = add_pwd(get_env(shell->env, "PWD"), cmd->cmd_name); // maybe join pwd
	else
		full_cmd = find_path(ft_split(get_env(shell->env, "PATH"), ':'), cmd->cmd_name);
	// if (check_not_dir(full_cmd)
	//	 exit(126); // minishell: full cmd: Is a directory
	ft_printf("full_cmd -[%s]\n", full_cmd);
	if (access(full_cmd, F_OK) == -1)
		exit (127); // recheck exit status command does not found
	if (access(full_cmd, X_OK) == -1)
		exit (126); // recheck exit status command exists but not executable
	execve(full_cmd, cmd->args, shell->env->envp);
	exit (127); // recheck status return strerror erno 
}

void	pre_exec_cmd(t_cmd *cmd, t_shell *shell)
{
	signal(SIGQUIT, handler_child_quit); // write coredump and exit with correct exit status;
	if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
	{
		close_all(shell);
		exit(1); // what status? what message?
	}
	close_all(shell);
	if (cmd->cmd_name)
	{
		if (is_cmd(cmd->cmd_name))
			run_cmd(cmd, shell->env);
		if (!ft_strncmp(cmd->cmd_name, "exit", ft_strlen("exit")))
			exit (0);
		exec_cmd(cmd, shell);
	}
	else
		exit(0);
}

void	run_multi_commands(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->cmds_count)
	{
		shell->cmds_arr[i]->pid = fork();
		if (shell->cmds_arr[i]->pid == -1)
			ft_printf("minishell: fork:\n"); //strerror(errno)
		else if (shell->cmds_arr[i]->pid > 0)
		{
			signal(SIGINT, sig_int_proc);
			signal(SIGQUIT, sig_int_proc);
			shell->pid_c = shell->cmds_arr[i]->pid;
		}
		else if (shell->cmds_arr[i]->pid == 0)
			pre_exec_cmd(shell->cmds_arr[i], shell);
	}
}

void	set_last_status(t_shell *shell, t_cmd *child, int wstat)
{
	if (WIFEXITED(wstat))
		set_env(shell->env, "?", ft_itoa(WEXITSTATUS(wstat)));
	else if (WIFSIGNALED(wstat))
		set_env(shell->env, "?", ft_itoa(WTERMSIG(wstat) + 128));
	set_env(shell->env, "_", child->cmd_name);
}

t_cmd	*who_returned(t_shell *shell, int pid)
{
	int	i;

	i = -1;
	while (++i < shell->cmds_count)
	{
		if (shell->cmds_arr[i]->pid == pid)
			return (shell->cmds_arr[i]);
	}
	return (NULL);
}

void	wait_all_children(t_shell *shell)
{
	int			i;
	int			ret;
	int			wstat;
	t_cmd		*cmd;

	i = -1;
	wstat = 0;
	while (++i < shell->cmds_count)
	{
		ret = waitpid(0, &wstat, 0); 
		cmd = who_returned(shell, ret);
		set_last_status(shell, cmd, wstat);
		if (cmd)
		{
			if (cmd->fd[0] != 0)
				close(cmd->fd[0]);
			if (cmd->fd[1] != 1)
				close(cmd->fd[1]);
		}
	}
}

void	pipex(t_shell *shell)
{
	if (shell->cmds_count == 1 && is_nofork(shell->cmds_arr[0]->cmd_name))
	{
		run_nofork(shell->cmds_arr[0], shell->env);
		return ;
	}
	else
		run_multi_commands(shell);
	wait_all_children(shell);
}
