/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:09:55 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		n;
	int		i;
	int		j;

	if (!s || !c)
		return (NULL);
	n = ft_wordcount(s, c);
	if (!(str = (char **)malloc(sizeof(str) * (n + 2))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (j < n && s[i])
	{
		str[j] = ft_wordfound(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
