/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:52:38 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 05:59:04 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
	// check_exit(); ADD _CHECK EXIT
	if (nord_stream(shell) || put_redir_cmds(shell))
		return (1);
	return (0);
}
