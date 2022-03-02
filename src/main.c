/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:31:36 by rusty             #+#    #+#             */
/*   Updated: 2022/03/03 00:59:16 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_shell(t_shell *shell, char **envp)
{
	char	*buf;

	ft_bzero(shell, sizeof(t_shell));
	shell->env = init_env(envp);
	buf = ft_itoa(ft_atoi(get_env(shell->env, "SHLVL")) + 1);
	set_env(shell->env, "SHLVL", buf);
	return (0);
}

void	execute_input(t_shell *shell, char *read)
{
	char	*str;
	char	**parsed;

	str = ft_strdup(read);
	// check_input(str);
	str = cut_spaces(str);
	// printf("%s\n", str);

	str = put_global(shell->env, str);
	// printf("%s\n", str);
	parsed = parse_pipes(str);
	if (!parsed)
		return ;
	shell->cmds_count = ft_split_len(parsed);
	if (!init_commands(shell, parsed))
		pipex(shell);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*read;

	(void)argc;
	(void)argv;
	g_heap.shell = (void *)&shell;
	g_heap.count = 0;
	if (init_shell(&shell, envp))
		return (1); // ?
	while (!shell.exit)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sig_int_empty);
		read = readline(PROMPT);
		if (check_exit_eof(read))
			break ;
		if (ft_strlen(read) > 0)
			add_history(read);
		execute_input(&shell, read);
		free(read);
	}
	ft_free();
	return (shell.exit_status);
}
