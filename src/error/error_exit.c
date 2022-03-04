/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:31:07 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/04 04:26:29 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	err_ext_return_one(char *module, char *text, char *name)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	err_exit(char *module, char *cmd, int ex_status)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	perror(cmd);
	exit(ex_status);
}

int	err_exit_txt(char *module, char *text, char *name, int status)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	exit(status);
}
