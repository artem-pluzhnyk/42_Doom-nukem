/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:47:46 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = (char *)h;
	if (!ft_strlen(n))
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == n[j] && i + j < len)
		{
			if (n[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
