/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:34:44 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 02:19:35 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>

# include "../redirect/redirect.h"
# include "../commands/commands.h"
# include "../libftv2/libftv2.h"
# include "../signals/signals.h"
# include "../shell/shell.h"
# include "../env/env.h"
# include "../builtin/builtin.h"

void	pipex(t_shell *shell);

#endif