/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:27:12 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/28 03:47:19 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_env(t_env *env, char *param)
{
	int		i;
	char	*value;

	if (!env || !param || !env->envp)
		return (err_return_null(M_ENV, ERR_NULL_PARAMS));
	i = 0;
	param = ft_strjoin(param, "=");
	while (env->envp[i])
	{
		if (strncmp(env->envp[i], param, ft_strlen(param)) == 0)
		{
			value = ft_strdup(ft_strchr(env->envp[i], '=') + 1);
			return (value);
		}
		i++;
	}
	return (ft_strdup(" "));
}
