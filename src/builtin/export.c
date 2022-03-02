/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:52:33 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/02 15:46:02 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	export_par(t_env *env, char *str, char **err_str)
{
	char	*par;
	char	*val;

	if (str[0] == '=')
		return (1);
	if (!strchr(str, '='))
	{
		par = ft_strtrim(str, " ");
		val = ft_strdup("");
	}
	else
	{
		par = ft_substr(str, 0, ft_strchr(str, '=') - str);
		val = ft_strtrim(ft_strchr(str, '=') + 1, " ");
	}
	if (!*par && check_env_par(par))
		*err_str = par;
	printf("EXP %s - %s \n", par, val);
	return (set_env(env, par, val));
}

int	cmd_export(char **args, t_env *env)
{
	char	*err_msg;
	int		i;

	i = 0;
	err_msg = 0;
	while (args && args[i])
	{
		printf("exp -%d \n", export_par(env, args[i], &err_msg));
		i++;
	}
	if (err_msg)
		return (err_ext_return_one(M_EXP, ERR_NOT_A_I, err_msg));
	return (0);
}
