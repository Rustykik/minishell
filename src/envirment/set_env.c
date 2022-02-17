/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:32:52 by rusty             #+#    #+#             */
/*   Updated: 2022/02/18 02:22:00 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	param_exists(t_env *env, char *param)
{
	char	*envp;

	envp = env->envp;
	while (*envp++)
		if (!ft_strncmp(*envp, param, ft_strlen(param)))
			return (*envp);
	return (NULL);
}

void	add_param(t_env *env, char *join, char **envp)
{
	int	i;

	i = -1;
	env->envp = ft_zalloc(sizeof(char *) * (env->len + 2));
	while (++i < env->length)
		env->vars[i] = envp[i];
	env->envp[i] = join;
	++env->len;
}

void	set_env(t_env *env, char *param, char *val)
{
	char	**new_envp;
	char	*join;
	char	*exists;

	join = ft_multi_join(param, "=", val);
	exists = param_exists(env, param);
	if (!exists)
		add_param(env, join, env->envp);
	else
		exists = join;
}
