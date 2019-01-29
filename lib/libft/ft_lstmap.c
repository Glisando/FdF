/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:30:46 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 11:10:42 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *res;

	if (!lst || !f)
		return (NULL);
	new = f(ft_lstnew(lst->content, lst->content_size));
	res = new;
	lst = lst->next;
	while (lst)
	{
		new->next = f(ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
		new = new->next;
	}
	return (res);
}
