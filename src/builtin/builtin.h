/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:26:01 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/26 18:48:35 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"
# include "../error/error.h"
# include "../const.h"

int	cmd_echo(char **args, t_env *env);
int	cmd_cd(char **args, t_env *env);
int	cmd_pwd(char **args, t_env *env);
int	cmd_env(char **args, t_env *env);
int	cmd_unset(char **args, t_env *env);
int	cmd_export(char **args, t_env *env);

int	check_env_par(char *param);

#endif