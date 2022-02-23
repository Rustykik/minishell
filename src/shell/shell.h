/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:19:05 by rusty             #+#    #+#             */
/*   Updated: 2022/02/23 12:10:37 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../commands/commands.h"
# include "../env/env.h"

typedef struct s_cmd	t_cmd;
typedef struct s_shell	t_shell;

struct	s_cmd
{
	char	*cmd;
	char	*input;
	int		fd[2];
	int		*fds;
};

struct s_shell
{
	char	*input;
	t_env	*env;
	int		cmds_count;
	t_cmd	**cmds_arr;
	int		cmds;
	int		exit;//???
	int		exit_status;
};

#endif