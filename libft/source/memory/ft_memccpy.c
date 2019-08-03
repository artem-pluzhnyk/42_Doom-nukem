/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 17:15:08 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	n;

	n = (unsigned char)c;
	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	while (i < len)
	{
		s2[i] = s1[i];
		if (s2[i] == n)
		{
			return (s2 + i + 1);
		}
		i++;
	}
	return (0);
}
