/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:22:07 by rusty             #+#    #+#             */
/*   Updated: 2022/02/22 12:42:30 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libftv2/ft_zalloc/ft_zalloc.h"
# include "../libftv2/libft/libft.h"

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
char	*get_env(t_env *env, char *param);

#endif