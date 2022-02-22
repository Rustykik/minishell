/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 05:17:50 by rusty             #+#    #+#             */
/*   Updated: 2022/02/19 07:31:55 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_env(t_env *env, char *param)
{
	char	*to_find;
	char	*val;

	to_find = param_exists(env, ft_strjoin(param, "="));
	if (!to_find)
		return (ft_strdup(" "));
	val = ft_strdup(ft_strchr(to_find, '=') + 1);
	return (val);
}
