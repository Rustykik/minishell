/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:12:34 by rusty             #+#    #+#             */
/*   Updated: 2022/02/26 21:57:31 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../commands/commands.h"
# include "../redirect/redirect.h"
# include "../libftv2/libftv2.h"
# include "../env/env.h"

# include "stdio.h" //delete me

char	*cut_spaces(char *input);
char	*put_global(t_env *env, char *str);
char	**parse_pipes(char *input);

int		parse_commands(t_cmd *cmd);
int		parse_redir(t_cmd *cmd);

#endif