/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:42:36 by rusty             #+#    #+#             */
/*   Updated: 2022/02/23 20:00:37 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_redir_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr("<>", str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	while (str[i] && !ft_strchr("<> ", str[i]))
		i++;
	return (i);
}

int	check_redir(char *str)
{
	if (str[0] == '>' && str[1] == '<')
		return (1);
	if (!ft_strchr("<>", *str))
		return (1);
	if (ft_strchr("<>", *str))
		str++;
	if (ft_strchr("<>", *str))
		str++;
	while (*str == ' ')
		str++;
	if (ft_strchr("<>", *str))
		return (1);
	return (0);
}

t_redir	*create_redir(char *str)
{
	t_redir	*new;

	if (check_redir(str))
		return (NULL);
	new = ft_zalloc(sizeof(t_redir));
	if (str[0] == '<' && str[1] == '<')
		new->type = IN_DOC;
	else if (str[0] == '>' && str[1] == '>')
		new->type = OUT_DOC;
	else if (str[0] == '<')
		new->type = IN;
	else if (str[0] == '>')
		new->type = OUT;
	while (ft_strchr("<> ", str))
		++str;
	new->file = ft_strdup(str);
	if (!new->file[0] || open_file(new))
	{
		close_redir();
		return (NULL);
	}
	return (new);
}

int	put_redir(t_cmd *cmd, char *str)
{
	t_redir	*red;

	red = create_redir(str);
	if (!red)
		return (1);
}

int	parse_redir(t_cmd *cmd)
{
	int		i;
	char	quote;
	char	*tmp;

	i = 0;
	while (cmd->input[i])
	{
		if (ft_strchr("\'\"", cmd->input[i]))
		{
			quote = cmd->input[i++];
			while (cmd->input[i] && cmd->input[i] != quote)
				++i;
		}
		if (ft_strchr("<>", cmd->input[i]))
		{
			tmp = ft_substr(&str[i], 0, get_redir_len(&str[i]));
			if (put_redir(cmd, tmp))
				return (1); // bash: syntax error wrong redirects
			i += get_redir_len(&str[i]);
		}
	}
	return (0);
}

int	parse_redir_cmds(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->cmds_count)
		if (parse_redir(shell->cmds_arr[i]) || \
		parse_commands(shell->cmds_arr[i]))
			return (1);
	return (0);
}
