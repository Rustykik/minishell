/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:47:02 by rusty             #+#    #+#             */
/*   Updated: 2022/02/22 11:52:20 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*put_paths(char **envp)
{
	while (*envp++)
		if (!ft_strncmp(*envp, "PATH=", ft_strlen("PATH=")))
			return (*envp + ft_strlen("PATH="));
	return (NULL);
}

void	copy_envp(t_env *env, char **envp)
{
	int	i;

	i = -1;
	env->envp = ft_zalloc(sizeof(char *) * (env->len + 1));
	while (++i < env->len)
		env->envp[i] = ft_strdup(envp[i]);
}

t_env	*put_envp(char **envp)
{
	t_env	*env;

	env = ft_zalloc(sizeof(t_env));
	env->len = 0;
	while (envp[env->len])
		++env->len;
	copy_envp(env, envp);
	env->paths = put_paths(envp);
	set_env(env, "?", "0");
	return (env);
}
