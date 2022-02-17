/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:47:02 by rusty             #+#    #+#             */
/*   Updated: 2022/02/18 02:22:07 by rusty            ###   ########.fr       */
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
	env->envp = ft_zalloc(sizeof(char **) * (env->len + 1));
	while (++i < env->len)
		env->envp[i] = ft_strdup(envp[i]);
}

t_env	*put_envp(char **envp)
{
	t_env	*env;
	int		len;

	env->len = 0;
	while (envp[env->len])
		++env->len;
	env = ft_zalloc(sizeof(t_env));
	copy_envp(env, envp);
	env->paths = put_paths(envp);
	set_env(env, "?", "0");
	return (env);
}
