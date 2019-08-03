/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:09:42 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/02 19:24:12 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	render_startend(t_main *m)
{
	int		x;

	x = REND.beginx - 1;
	while (++x <= REND.endx)
	{
		render_init5(m, x);
		if (REND.neighbor >= 0)
			render_init6(m, x);
		else
		{
			REND.texture_id = 7;
			REND.color = 0xa03623;
			vline(m, x, REND.cya, REND.cyb); // Walls
		}
	}
}

void	render_init5(t_main *m, int x)
{
	REND.z = ((x - REND.x1) * (REND.tz2 - REND.tz1) / (REND.x2 - REND.x1) + REND.tz1) * 8;
	REND.ya = (x - REND.x1) * (REND.y2a - REND.y1a) / (REND.x2 - REND.x1) + REND.y1a;
	REND.cya = CLAMP(REND.ya, REND.ytop[x], REND.ybottom[x]);
	REND.yb = (x - REND.x1) * (REND.y2b - REND.y1b) / (REND.x2 - REND.x1) + REND.y1b;
	REND.cyb = CLAMP(REND.yb, REND.ytop[x], REND.ybottom[x]);
	REND.texture_id = 6;
	REND.color = 0x00BFFF;
	vline(m, x, REND.ytop[x], REND.cya - 1); // Celing
	REND.texture_id = 9;
	REND.color = 0x3f9b0b;
	vline(m, x, REND.cyb + 1, REND.ybottom[x]); // Floor
}

void	render_init6(t_main *m, int x)
{
	REND.nya = (x - REND.x1) * (REND.ny2a - REND.ny1a) / (REND.x2 - REND.x1) + REND.ny1a;
	REND.cnya = CLAMP(REND.nya, REND.ytop[x], REND.ybottom[x]);
	REND.nyb = (x - REND.x1) * (REND.ny2b - REND.ny1b) / (REND.x2 - REND.x1) + REND.ny1b;
	REND.cnyb = CLAMP(REND.nyb, REND.ytop[x], REND.ybottom[x]);
	REND.r1 = 0x010101 * (255 - REND.z);
	REND.r2 = 0x040007 * (31 - REND.z / 8);
	REND.texture_id = 8;
	REND.color = 0x464196;
	vline(m, x, REND.cya, REND.cnya - 1); // Top missing
	REND.ytop[x] = CLAMP(MAX(REND.cya, REND.cnya), REND.ytop[x], (int)WIN_H - 1);
	REND.texture_id = 8;
	REND.color = 0x464196;
	vline(m, x, REND.cnyb + 1, REND.cyb); // Bottom missing
	REND.ybottom[x] = CLAMP(MIN(REND.cyb, REND.cnyb), 0, REND.ybottom[x]);
}

void	render_last(t_main *m)
{
		if (REND.neighbor >= 0 && REND.endx >= REND.beginx
		&& (REND.head + MAXQUEUE + 1 - REND.tail) % MAXQUEUE)
		{
			REND.head->sectorno = REND.neighbor;
			REND.head->sx1 = REND.beginx;
			REND.head->sx2 = REND.endx;
			if (++REND.head == REND.queue + MAXQUEUE)
				REND.head = REND.queue;
		}
}
