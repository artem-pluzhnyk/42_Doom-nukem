/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:27:43 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/04 14:28:51 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_xy	intersect(t_main *m)
{
	t_xy	s;

	s.x = VXS(VXS(IS.x1,IS.y1, IS.x2,IS.y2), (IS.x1)-(IS.x2),
	VXS(IS.x3,IS.y3, IS.x4,IS.y4), (IS.x3)-(IS.x4)) / VXS((IS.x1)-(IS.x2),
	(IS.y1)-(IS.y2), (IS.x3)-(IS.x4), (IS.y3)-(IS.y4));
	s.y = VXS(VXS(IS.x1,IS.y1, IS.x2,IS.y2), (IS.y1)-(IS.y2),
	VXS(IS.x3,IS.y3, IS.x4,IS.y4), (IS.y3)-(IS.y4)) / VXS((IS.x1)-(IS.x2),
	(IS.y1)-(IS.y2), (IS.x3)-(IS.x4), (IS.y3)-(IS.y4));
	return (s);
}

void	scaler_init(t_main *m, int a, int b, int c, int d, int f)
{
	SCAL.result = d + (b - 1 - a) * (f - d) / (c - a);
	SCAL.bop = ((f < d) ^ (c < a)) ? -1 : 1;
	SCAL.fd = abs(f - d);
	SCAL.ca = abs(c - a);
	SCAL.cache = (int)((b - 1 - a) * abs(f - d)) % abs(c - a);
}

int		scaler_next(t_scaler *i)
{
	i->cache += i->fd;
	while (i->cache >= i->ca)
	{
		i->result += i->bop;
		i->cache -= i->ca;
	}
	return (i->result);
}
