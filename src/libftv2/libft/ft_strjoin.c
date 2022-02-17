/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:11:48 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/11 13:56:59 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	ret = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, ft_strlen(s1));
	ft_strlcpy(ret + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (ret);
}
