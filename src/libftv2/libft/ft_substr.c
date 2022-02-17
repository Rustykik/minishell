/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:50:50 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/15 16:53:29 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sze;

	if (s == NULL)
		return (NULL);
	if ((size_t) start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	sze = (size_t)ft_min(ft_strlen(s + start), len);
	ret = ft_calloc(sze + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, sze + 1);
	return (ret);
}
