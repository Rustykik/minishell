/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:53:49 by rusty             #+#    #+#             */
/*   Updated: 2022/03/02 14:55:44 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_commands(t_cmd *cmd)
{
	int		i;
	char	*input;
	char	quote;

	i = -1;
	input = cmd->input;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				++i;
		}
		input[i] = input[i] * !(input[i] == ' ') + '\6' * (input[i] == ' ');
	}
	cmd->args = ft_split(input, '\6');
	cmd->cmd_name = cmd->args[0];
	// cmd->abs_path = get_abs_path
	return (0);
}
