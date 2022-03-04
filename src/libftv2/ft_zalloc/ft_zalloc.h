/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:54:48 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 15:59:28 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ZALLOC_H
# define FT_ZALLOC_H

# include "../libft/libft.h"
# include "../libftmp/libftmp.h"

typedef struct s_heap	t_heap;

struct					s_heap
{
	void	**mem;
	void	**tmp_mem;
	size_t	count;
	size_t	tmp_count;
	void	*shell;	
};

void	*ft_zalloc(size_t size);
void	*ftmp_zalloc(size_t size);
void	ft_free(void);
void	ftmp_free(void);
void	alloc_error(int size);

t_heap					g_heap;

#endif