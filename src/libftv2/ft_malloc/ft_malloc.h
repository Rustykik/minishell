/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:54:48 by rusty             #+#    #+#             */
/*   Updated: 2022/02/17 21:28:47 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft/libft.h"

typedef struct s_heap	t_heap;

struct	s_heap
{
	void	**mem;
	void	**mem_tmp;
	size_t	count;
	size_t	count_tmp;	
};

void	*ft_malloc(size_t size);
void	ft_free(void);

#endif