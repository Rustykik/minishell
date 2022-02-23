/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:09:40 by rusty             #+#    #+#             */
/*   Updated: 2022/02/23 12:25:47 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../libftv2/libftv2.h"
# include "../parser/parser.h"
# include "../shell/shell.h"
# include "../minishell.h"

void	init_commands(t_shell *shell, char **parsed);

#endif