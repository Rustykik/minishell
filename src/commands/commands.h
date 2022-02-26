/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:09:40 by rusty             #+#    #+#             */
/*   Updated: 2022/02/26 21:54:52 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../redirect/redirect.h"
# include "../libftv2/libftv2.h"

typedef struct s_cmd	t_cmd;

struct	s_cmd
{
	char	*input;
	char	*cmd_name;
	char	**args;
	int		fd[2];
	// int		*fds;
	t_redir	*left;
	t_redir	*right;
};

int	put_redir(t_cmd *cmd, char *str);

#endif