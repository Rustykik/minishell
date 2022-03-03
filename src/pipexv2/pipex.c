/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:34:16 by rusty             #+#    #+#             */
/*   Updated: 2022/03/03 20:05:40 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **paths, char *cmd)
{
	int		i;
	char	*name;

	i = -1;
	while (paths[++i])
	{
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
			name = ft_multi_join(3, paths[i], "/", cmd);
		else
			name = ft_strjoin(paths[i], cmd);
		if (!access(name, F_OK))
			return (name);
	}
	err_exit_txt(M_SH, cmd, ERR_NO_COMM, 127);
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
	return (NULL);
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

int	check_not_dir(char *full_cmd)
{
	DIR	*dir;

	dir = opendir(full_cmd);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

void	exec_cmd(t_cmd *cmd, t_shell *shell)
{
	char	*full_cmd;

	if (cmd->cmd_name[0] == '.')
		full_cmd = add_pwd(get_env(shell->env, "PWD"), cmd->cmd_name);
	else
		full_cmd = find_path(ft_split(get_env(shell->env, "PATH"), ':'), cmd->cmd_name);
	if (check_not_dir(full_cmd))
		err_exit_txt(M_SH, cmd->cmd_name, ERR_IS_DIREC, 126);
	if (access(full_cmd, F_OK) == -1)
		err_exit_txt(M_SH, cmd->cmd_name, ERR_NO_COMM, 127);	
	if (access(full_cmd, X_OK) == -1)
		err_exit(M_SH, cmd->cmd_name, 126);
	execve(full_cmd, cmd->args, shell->env->envp);
	exit (127); 
}

void	pre_exec_cmd(t_cmd *cmd, t_shell *shell)
{
	int err;
	
	signal(SIGQUIT, handler_child_quit); // write coredump and exit with correct exit status;
	if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
	{
		err = errno;
		close_all(shell);
		err_exit_txt(M_SH, "dup2", strerror(err), 1); // ??? HZ exit status
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
			perror("minishell: fork"); //strerror(errno)
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
