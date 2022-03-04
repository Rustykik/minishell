/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:36:08 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 03:28:02 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

// # include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# include <readline/readline.h>
# include "../libftv2/libftv2.h"
// # include "../signals/signals.h"
// # include "../commands/commands.h"
// # include "../shell/shell.h"

# define IN 1
# define OUT 2
# define IN_DOC 3
# define OUT_DOC 4

typedef struct s_redir	t_redir;

struct s_redir
{
	int		type;
	int		fd;
	char	*file;
};

int	open_file(t_redir *new);

#endif