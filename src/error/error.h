/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:53:07 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/04 12:59:39 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../libftv2/libft/libft.h"
# include "../const.h"
# include "stdio.h"

int		err_return_one(char *module, char *text);
void	*err_return_null(char *module, char *text);
int		err_return_zero(char *module, char *type);
int		err_return_zero(char *module, char *type);

int		err_ext_return_one(char *module, char *text, char *name);
int		err_exit(char *module, char *cmd, int ex_status);
int		err_exit_txt(char *module, char *text, char *name, int status);

#endif