/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:45:15 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *str)
{
	float	res;
	float	res2;
	char	*s;
	int		len;

	s = (char *)str;
	res = (float)ft_atoi(s);
	while (*s && *s != '.')
		s++;
	if (*s == '.')
		s++;
	res2 = (float)ft_atoi(s);
	len = ft_strlen(s);
	while (len--)
		res2 /= 10;
	return (res + ((res > 0) ? res2 : -res2));
}
