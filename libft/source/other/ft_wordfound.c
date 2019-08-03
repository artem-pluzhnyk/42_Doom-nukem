/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordfound.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:12:46 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 14:09:55 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_wordfound(const char *s, char c, int *i)
{
	char	*str;
	int		j;

	if (!(str = (char *)malloc(sizeof(str) * (ft_strlen(s)))))
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		str[j] = s[*i];
		j++;
		*i += 1;
	}
	str[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (str);
}
