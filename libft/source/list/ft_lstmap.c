/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:08:13 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *newlst;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	ret = newlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlst->next = f(lst)))
		{
			free(newlst->next);
			return (NULL);
		}
		newlst = newlst->next;
	}
	return (ret);
}
