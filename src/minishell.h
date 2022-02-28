/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:32:16 by rusty             #+#    #+#             */
/*   Updated: 2022/02/28 02:37:40 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>

# include "./libftv2/ft_zalloc/ft_zalloc.h"
# include "./libftv2/libft/libft.h"

// # include "./libftv2/libftv2.h"
# include "./commands/commands.h"
# include "./pipexv2/pipex.h"
# include "./parser/parser.h"
# include "./shell/shell.h"
# include "./env/env.h"
# include "./const.h"
#endif