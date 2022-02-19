/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:22:07 by rusty             #+#    #+#             */
/*   Updated: 2022/02/19 11:22:41 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libftv2/libftv2.h"

typedef struct s_env	t_env;

struct	s_env
{
	char	**envp;
	char	*paths;
	int		len;
};

t_env	*put_envp(char **envp);
void	set_env(t_env *env, char *param, char *val);
char	*param_exists(t_env *env, char *param);

#endif