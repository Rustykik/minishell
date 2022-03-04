/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_in_outs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:20:26 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 03:37:33 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"

void	here_doc_handler(int signum)
{
	if (signum == SIGINT)
	{
		kill(g_heap.pid_c, SIGINT);
		write(2, "\n", 1);
		signal(SIGINT, SIG_IGN);
	}
}

int	ret_status_here_doc(int wstat)
{
	if (WIFEXITED(wstat))
		return (WEXITSTATUS(wstat));
	else if (WIFSIGNALED(wstat))
		return (WTERMSIG(wstat) + 128);
	return (1);
}

int	wait_doc(void)
{
	int		wstat;
	// int		ret;

	wstat = 0;
	waitpid(0, &wstat, 0);
	g_heap.input_stat = ret_status_here_doc(wstat);
	return (1);
}

int	here_doc(t_redir *new)
{
	char	*line;

	while (1)
	{
		write(2, "> ", 2);
		line = ft_get_next_line(0);
		if (!line)
			return (0); //minishell: here-document delimited by end-of-file (wanted `lim')
		if (!ft_strncmp(line, new->file, ft_strlen(new->file)))
		{
			free(line);
			break ;
		}
		else
		{
			ft_putstr_fd(line, 1);
			write(1, "\n", 1);
		}
		free(line);
	}
	// close(fd[1]); //??
	// close(fd[0]);
	exit(0);
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
	int	fd[2];

	if (new->type == IN_DOC)
	{
		signal(SIGINT, here_doc_handler);
		if (pipe(fd) == -1)
			return (1); // pipex eror minishell: (strerror erno)
		g_heap.pid_c = fork();
		if (g_heap.pid_c < 0)
			return (1); // fork error
		else if (g_heap.pid_c == 0)
		{
			dup2(fd[1], 1);
			dup2(fd[0], 0);
			close(fd[1]);
			close(fd[0]);
			here_doc(new);
		}
		else if (g_heap.pid_c > 0)
		{
			dup2(fd[0], 0);
			new->fd = fd[0];
			close(fd[1]);
		}
		return (wait_doc());
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
