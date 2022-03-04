/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:52:38 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 18:26:41 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_isstrdigit(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	check_exit_str(t_shell *shell)
{
	int		i;
	char	**sp;

	i = 0;
	// if (shell->cmds != 1)
	// 	return ;
	sp = ft_split(shell->cmds_arr[0]->input, ' ');
	while (sp[i])
		i++;
	if (!ft_strncmp(sp[0], "exit", ft_strlen("exit")))
	{
		shell->exit = 1;
		if (i > 1)
			shell->exit_status = ft_atoi(sp[1]);
		if (i > 1 && !ft_isstrdigit(sp[1]))
		{
			err_return_one("Exit", ERR_NE_ARGS);
			shell->exit_status = 255;
		}
		else if (i > 2)
		{
			shell->exit = 0;
			err_return_one("Exit", ERR_MN_ARGS);
		}
	}
}

t_cmd	*init_cmd(char *cmd)
{
	t_cmd	*ret;

	ret = ft_zalloc(sizeof(t_cmd));
	ret->input = ft_strtrim(cmd, " ");
	ret->fd[0] = 0;
	ret->fd[1] = 1;
	return (ret);
}

int	nord_stream(t_shell *shell)
{
	int	i;
	int	fd[2];

	i = 0;
	while (++i < shell->cmds_count)
	{
		if (pipe(fd) < 0)
			return (1); // pipe error
		shell->cmds_arr[i]->fd[0] = fd[0];
		shell->cmds_arr[i - 1]->fd[1] = fd[1];
	}
	return (0);
}

int	init_commands(t_shell *shell, char **parsed)
{
	int	i;

	shell->cmds_arr = ft_zalloc(sizeof(t_cmd *) * shell->cmds_count);
	i = -1;
	while (++i < shell->cmds_count)
		shell->cmds_arr[i] = init_cmd(parsed[i]);
	check_exit_str(shell);
	if (nord_stream(shell) || put_redir_cmds(shell))
		return (1);
	return (0);
}
