/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:31:07 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/28 03:55:31 by rusty            ###   ########.fr       */
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
