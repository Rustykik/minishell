/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:22:07 by rusty             #+#    #+#             */
/*   Updated: 2022/02/18 02:24:40 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env	t_env;

struct	s_env
{
	char	**envp;
	char	*paths;
	int		len;
};

t_env	*put_envp(char **envp);
void	set_env(t_env *env, char *param, char *val);
#endif