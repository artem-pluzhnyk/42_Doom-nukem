/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:04:27 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;
	void	*newlst_cont;
	size_t	newlst_size;

	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		newlst_cont = ft_memalloc(content_size);
		ft_memcpy(newlst_cont, content, content_size);
		newlst_size = content_size;
		newlst->content = newlst_cont;
		newlst->content_size = newlst_size;
	}
	newlst->next = NULL;
	return (newlst);
}
