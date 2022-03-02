/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:26:01 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/02 16:25:42 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"
# include "../error/error.h"
# include "../commands/commands.h"
# include "../const.h"

# include <limits.h>

int	cmd_echo(char **args, t_env *env);
int	cmd_cd(char **args, t_env *env);
int	cmd_pwd(char **args, t_env *env);
int	cmd_env(char **args, t_env *env);
int	cmd_unset(char **args, t_env *env);
int	cmd_export(char **args, t_env *env);

int	is_cmd(char *str);
int	run_cmd(t_cmd *cmd, t_env *env);
int	is_nofork(char *cmd);
int	run_nofork(t_cmd *cmd, t_env *env);

int	check_env_par(char *param);

#endif