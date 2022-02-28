/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:19:39 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/28 03:47:37 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	args_length(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	cmd_cd(char **args, t_env *env)
{
	char	*tmp;
	int		status;

	if (args_length(args) == 0)
		return (0);	
	if (args_length(args) > 1)
		return (err_return_one(M_CD, ERR_MN_ARGS));
	if (chdir(args[0]) == -1)
		return (err_ext_return_one(M_CD, ERR_NO_FILE, args[0]));
	status = 0;
	tmp = get_env("PWD", env);
	if (set_env("OLDPWD", tmp, env))
		status = 1;
	tmp = getwd(tmp);
	if (set_env("PWD", tmp, env))
		status = 1;
	// free(tmp); !!! Показывает что ликов нет.
	return (status);
}
