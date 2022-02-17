/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:32:16 by rusty             #+#    #+#             */
/*   Updated: 2022/02/18 02:33:18 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libftv2/ft_zalloc/ft_zalloc.h"
# include "./libftv2/libft/libft.h"
# include "./enirment/env.h"

typedef struct s_shell	t_shell;

struct s_shell
{
	char	*input;
	t_env	*env;
	int		cmds;
	int		exit;//???
	int		exit_status;
};

#endif