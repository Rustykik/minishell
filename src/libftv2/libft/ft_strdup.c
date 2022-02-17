/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:29:43 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/10 20:40:24 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ret;
	size_t		len;

	len = ft_strlen(s1);
	ret = ft_calloc(sizeof(char), (len + 1));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, len);
	ret[len] = '\0';
	return (ret);
}
