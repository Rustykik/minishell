/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:17:49 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/03 01:49:16 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	env_par_exist(t_env *env, char *param)
{
	int	i;

	i = 0;
	while (env->envp[i] && i < env->len)
	{
		if (ft_strncmp(env->envp[i], param, ft_strlen(param)) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	new_envp_set(t_env *env, char *str, char **tmp)
{
	int	i;

	i = 0;
	env->envp = ft_zalloc(sizeof(char *) * (env->len + 2));
	while (i < env->len)
	{
		env->envp[i] = tmp[i];
		i++;
	}
	env->envp[i] = str;
	return (0);
}

void	rewrite_env_param(t_env *env, char *param, char *join)
{
	int	i;

	i = 0;
	while (i < env->len)
	{
		if (env->envp[i])
		{
			if (ft_strncmp(env->envp[i], param, ft_strlen(param)) == 0)
			{
				write(2, "rewrite\n", ft_strlen("rewrite\n"));
				env->envp[i] = join;
			}
		}
		i++;
	}
}

int	set_env(t_env *env, char *param, char *val)
{
	char	**tmp;
	char	*join;

	if (!env || !param || !val)
		return (1);
	join = ft_multi_join(3, param, "=", val);
	if (env_par_exist(env, param))
	{
		write(2, "Exists\n", ft_strlen("Exists\n"));
		rewrite_env_param(env, param, join);
	}
	else
	{
		write(2, "not Exists\n", ft_strlen("not Exists\n"));
		tmp = env->envp;
		new_envp_set(env, join, tmp);
		env->len++;
	}
	return (0);
}
