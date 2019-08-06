/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:38:51 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsplit(char const *s, char c)
{
	t_list	*lst;
	int		i;
	char	**nlst;

	if (!s || !c)
		return (NULL);
	nlst = ft_strsplit(s, c);
	lst = NULL;
	i = 0;
	while (i < ft_wordcount(s, c))
	{
		ft_lstadd(&lst, ft_lstnew(nlst[i], ft_strlen(nlst[i])));
		i++;
	}
	return (lst);
}
