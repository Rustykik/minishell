/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:34:44 by rusty             #+#    #+#             */
/*   Updated: 2022/03/03 19:07:10 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <errno.h>

# include "../commands/commands.h"
# include "../libftv2/libftv2.h"
# include "../signals/signals.h"
# include "../builtin/builtin.h"
# include "../error/error.h"
# include "../shell/shell.h"
# include "../env/env.h"

void	pipex(t_shell *shell);

#endif