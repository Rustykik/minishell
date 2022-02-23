/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:47:13 by rusty             #+#    #+#             */
/*   Updated: 2022/02/23 09:24:16 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*replace_pipes(char *input)
{
	int		i;
	char	quote;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				++i;
			if (!input[i])
				return (NULL);
		}
		if (input[i] == '|')
			input[i] = '\6';
	}
	return (input);
}

char	*check_pipe(char *str)
{
	int		i;
	int		pipe_repeat;

	pipe_repeat = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			++i;
		if (str[i] == '\6' && pipe_repeat)
			return (NULL);
		else if (str[i] == '\6')
			pipe_repeat = 1;
		else
			pipe_repeat = 0;
		if (str[i])
			++i;
	}
	while (i > 0 && str[i] == ' ')
			--i;
	if (str[i] == '\6')
		return (NULL);
	else
		return (str);
}

char	**parse_pipes(char *input)
{
	char	**ret;

	input = replace_pipes(input);
	if (!input)
		return (NULL); // unclosed quotes 
	input = ft_strtrim(input, " "); // may be delete
	if (!input)
		return (NULL);
	ret = ft_split(check_pipe(input), '\6');
	if (!ret)
		return (NULL); //bash: syntax error near unexpected token `|'
	return (ret);
}
