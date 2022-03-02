/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:53:49 by rusty             #+#    #+#             */
/*   Updated: 2022/03/02 17:59:38 by majacqua         ###   ########.fr       */
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
			quote = input[i];
			input[i++] = '\6';
			while (input[i] && input[i] != quote)
			{
				input[i] = input[i] * !(input[i] == ' ') + '\r' * (input[i] == ' ');
				++i;
			}
			if (input[i])
				input[i] = '\6';
		}
		// input[i] = input[i] * !(input[i] == ' ') + '\6' * (input[i] == ' ');
	}
	cmd->args = ft_split(input, '\6');
	char *tmp = cmd->args[0];
	i = 1;
	while (cmd->args[i])
	{
		tmp = ft_strjoin(tmp, cmd->args[i]);
		i++;
	}
	i = -1;
	// ТУТ НИЖНИЙ
	while (tmp[++i])
	{
		if (tmp[i] == '\'' || tmp[i] == '\"')
		{
			quote = tmp[i++];
			while (tmp[i] && tmp[i] != quote)
				++i;
		}
		tmp[i] = tmp[i] * !(tmp[i] == ' ') + '\6' * (tmp[i] == ' ');
	}
	tmp = ft_str_translate(tmp, '\r', ' ');
	cmd->args = ft_split(tmp, '\6');
	// for (int i = 0; cmd->args[i]; i++)
	// {
	// 	cmd->args[i] = ft_strtrim(cmd->args[i], "\"");
	// 	cmd->args[i] = ft_strtrim(cmd->args[i], "\'");
	// }
	cmd->cmd_name = cmd->args[0];
	return (0);
}
