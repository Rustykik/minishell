/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_zalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:20:18 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 17:37:05 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zalloc.h"

extern t_heap	g_heap;

void	tmp_alloc_error(int size)
{
	ft_putstr_fd("ftmp_zalloc: cannot allocate ", 2);
	ft_putnbr_fd(size, 2);
	ft_putstr_fd("bytes", 2);
	ft_free();
	exit(2);
}

void	ftmp_add(void *ptr)
{
	void		**new;
	size_t		i;

	new = malloc(sizeof(void *) * (g_heap.tmp_count + 1));
	if (!new)
		tmp_alloc_error(sizeof(void *) * (g_heap.tmp_count + 1));
	i = 0;
	while (i < g_heap.tmp_count)
	{
		new[i] = g_heap.tmp_mem[i];
		i++;
	}
	new[g_heap.tmp_count] = ptr;
	g_heap.tmp_count++;
	if (g_heap.tmp_mem)
		free(g_heap.tmp_mem);
	g_heap.tmp_mem = new;
}

void	*ftmp_zalloc(size_t size)
{
	void	*ptr;

	if (!g_heap.tmp_count)
	{
		g_heap.tmp_count = 0;
		g_heap.tmp_mem = NULL;
	}
	ptr = malloc(size);
	if (!ptr)
		tmp_alloc_error(size);
	ftmp_add(ptr);
	ft_bzero(ptr, size);
	return (ptr);
}
