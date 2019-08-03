/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 19:21:36 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/05 13:12:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isnegative(int *n, int *zn)
{
	if (*n < 0)
	{
		*n *= -1;
		*zn = 1;
	}
}

char		*ft_itoa(int n)
{
	int		t;
	int		l;
	int		zn;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	t = n;
	l = 2;
	zn = 0;
	ft_isnegative(&n, &zn);
	while (t /= 10)
		l++;
	l += zn;
	if (!(str = (char*)malloc(sizeof(char) * l)))
		return (NULL);
	str[--l] = '\0';
	while (l--)
	{
		str[l] = n % 10 + '0';
		n = n / 10;
	}
	if (zn)
		str[0] = '-';
	return (str);
}
