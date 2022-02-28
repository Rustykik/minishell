/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:18:06 by rusty             #+#    #+#             */
/*   Updated: 2022/02/28 16:33:22 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	check_redir(char *str)
{
	if (str[0] == '>' && str[1] == '<')
		return (1); // `<'
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
		return (NULL); //  bash: syntax error wrong redirects
	new = ft_zalloc(sizeof(t_redir));
	if (str[0] == '<' && str[1] == '<')
		new->type = IN_DOC;
	else if (str[0] == '>' && str[1] == '>')
		new->type = OUT_DOC;
	else if (str[0] == '<')
		new->type = IN;
	else if (str[0] == '>')
		new->type = OUT;
	while (ft_strchr("<> ", *str))
		++str;
	new->file = ft_strdup(str);
	if (!new->file[0] || open_file(new))
	{
		close(new->fd);
		return (NULL);
	}
	return (new);
}

int	put_redir(t_cmd *cmd, char *str)
{
	t_redir	*red;
	t_redir	*cur_redir;
	int		in_out;

	red = create_redir(str);
	if (!red)
		return (1);
	in_out = 1;
	cur_redir = cmd->right;
	if (red->type == IN || red->type == IN_DOC)
	{
		in_out = 0;
		cur_redir = cmd->left;
	}
	if (!cur_redir && cmd->fd[in_out] > 2)
		close(cmd->fd[in_out]);
	if (cur_redir)
		close(cur_redir->fd);
	cur_redir = red;
	if (cmd->left)
		cmd->fd[0] = cmd->left->fd;
	if (cmd->right)
		cmd->fd[1] = cmd->right->fd;
	return (0);
}
