/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:56:24 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/13 17:20:19 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	**rett;

	if (!lst)
		return (NULL);
	rett = &ret;
	ret = NULL;
	while (lst)
	{
		ft_lstadd_back(rett, ft_lstnew((*f)(lst->content)));
		if (!ft_lstlast(*rett))
		{
			ft_lstclear(rett, del);
			ret = NULL;
			return (ret);
		}
		lst = lst->next;
	}
	return (*rett);
}
