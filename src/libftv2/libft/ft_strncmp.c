/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:36:37 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/11 18:48:43 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 14:53:25 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/09/05 15:05:29 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;
	size_t	i;

	i = 1;
	ret = 0;
	if (n == 0)
		return (0);
	while (*((unsigned char *)s1) && *((unsigned char *)s2) && i < n)
	{
		if (*((unsigned char *)s1) == *((unsigned char *)s2))
		{
			++i;
			++s1;
			++s2;
		}
		else
			break ;
	}	
	ret = *((unsigned char *)s1) - *((unsigned char *)s2);
	return (ret);
}
