/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:34:44 by rusty             #+#    #+#             */
/*   Updated: 2022/03/02 14:35:18 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>

# include "../commands/commands.h"
# include "../libftv2/libftv2.h"
# include "../signals/signals.h"
# include "../shell/shell.h"
# include "../env/env.h"
# include "../builtin/builtin.h"

void	pipex(t_shell *shell);

#endif