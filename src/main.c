/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:31:36 by rusty             #+#    #+#             */
/*   Updated: 2022/02/19 10:51:40 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_shell(t_shell *shell)
{
	char	**envp;
	char	*buf;

	ft_bzero(shell, sizeof(t_shell));
	envp = getenv();
	shell->env = put_envp(envp);
	buf = ft_itoa(ft_atoi(get_env("SHLVL", shell->env)) + 1);
	set_env(shell->env, "SHLVL", buf);
	return (0);
}

// void	execute_input(t_shell *shell, char *read)
// {
// 	char	*str;

// 	str = ft_strdup(read);
// 	check_input(str);
// }

int	main(int argc, char **argv)
{
	t_shell	shell;
	char	*read;

	(void)argc;
	(void)argv;
	g_heap.shell = (void *)&shell;
	if (init_shell(&shell, envp))
		return (1); // ?
	while (!shell.exit)
	{
		shell.cmds = 0;// ?bzero
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sig_int_empty);
		read = readline(PROMPT);
		if (!read)
			break ;
		// if (check_int_skip(&shell, read))
		// 	continue ;
		if (ft_strlen(read) > 0)
			add_history(read);
		execute_input(&shell, read);
		free(read);
	}
	ft_free();
	return (shell.exit_status);
}
