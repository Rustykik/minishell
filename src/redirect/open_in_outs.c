/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_in_outs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:20:26 by rusty             #+#    #+#             */
/*   Updated: 2022/02/26 22:26:39 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"


int	here_doc(t_redir *new)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		return (1); // pipex eror minishell: (strerror erno)
	new->fd = fd[0];
	while (1)
	{
		line = readline(">");
		if (!line)
			return (0);
		if (!ft_strncmp(line, new->file, ft_strlen(new->file)))
		{
			free(line);
			break ;
		}
		else
		{
			ft_putstr_fd(line, fd[1]);
			// maybe write new line
		}
		free(line);
	}
	close(fd[0]);
	return (0);
}

int	out_file(t_redir *new)
{
	if (new->type == OUT)
		new->fd = open(new->file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	else if (new->type == OUT_DOC)
		new->fd = open(new->file, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (new->fd == -1)
		return (1); // strerror(errno)
	return (0);
}

int	open_file(t_redir *new)
{
	if (new->type == IN_DOC)
	{
		// signal(SIGINT, here_doc_handler);
		// signal(SIGINT, here_doc_handler);
		return (here_doc(new));
	}
	else if (new->type == IN)
	{
		new->fd = open(new->file, O_RDONLY);
		if (new->fd == -1)
			return (1); // strerror(errno) 
		return (0);
	}
	else
		return (out_file(new));
}
