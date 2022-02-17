/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:46:17 by rusty             #+#    #+#             */
/*   Updated: 2022/02/18 02:04:49 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*muljoin(char *str, va_list *args)
{
	char	*to_join;

	to_join = va_arg(*args, char const *);
	while (to_join)
	{
		str = ft_strjoin(str, to_join);
		to_join = va_arg(*args, char const *);
	}
	return (str);
}

char	*ft_multi_join(const char *str, ...)
{
	va_list	args;
	char	*ret;
	char	*to_work;

	to_work = ft_strdup(str);
	va_start(args, str);
	ret = muljoin(to_work, &args);
	va_end(args);
	return (ret);
}
