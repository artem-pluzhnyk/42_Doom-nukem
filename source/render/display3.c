/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:09:42 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/13 13:13:56 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	render_startend(t_main *m, int s)
{
	int		x;

	x = REND.beginx - 1;
	while (++x <= REND.endx)
	{
		REND.txtx = (REND.u0 * ((REND.x2 - x) * REND.tz2) + REND.u1 * ((x - REND.x1) * REND.tz1))
		/ ((REND.x2 - x) * REND.tz2 + (x - REND.x1) * REND.tz1);
		render_init5(m, x);
		if (REND.neighbor >= 0)
			render_init6(m, x);
		else
		{
			REND.txtr_id = SECT[REND.now.sectorno].texture[s];
			scaler_init(m, REND.ya, REND.cya, REND.yb, 0, 1024);
			vline2(m, x, REND.cya, REND.cyb, REND.txtx); // Walls
			// Posters
			// REND.txtr_id = 10;
			// if (REND.now.sectorno == 0 && s == 5
			// && x > (REND.beginx + 150) && x < (REND.endx - 150))
			// 	draw_poster(m, x, REND.cya + 100, REND.cyb - 100, REND.txtx);
		}
	}
}

void	render_init5(t_main *m, int x)
{
	REND.z = ((x - REND.x1) * (REND.tz2 - REND.tz1) / (REND.x2 - REND.x1) + REND.tz1) * 8;
	SREND.ZBuffer[x] = REND.z;
	REND.ya = (x - REND.x1) * (REND.y2a - REND.y1a) / (REND.x2 - REND.x1) + REND.y1a;
	REND.yb = (x - REND.x1) * (REND.y2b - REND.y1b) / (REND.x2 - REND.x1) + REND.y1b;
	REND.cya = CLAMP(REND.ya, REND.ytop[x], REND.ybottom[x]);
	REND.cyb = CLAMP(REND.yb, REND.ytop[x], REND.ybottom[x]);
	REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[REND.now.sectorno].npoints + 1];
	vline(m, x, REND.ytop[x], REND.cya - 1); // Ceiling
	REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[REND.now.sectorno].npoints];
	vline(m, x, REND.cyb + 1, REND.ybottom[x]); // Floor
}

void	render_init6(t_main *m, int x)
{
	REND.nya = (x - REND.x1) * (REND.ny2a - REND.ny1a) / (REND.x2 - REND.x1) + REND.ny1a;
	REND.cnya = CLAMP(REND.nya, REND.ytop[x], REND.ybottom[x]);
	REND.nyb = (x - REND.x1) * (REND.ny2b - REND.ny1b) / (REND.x2 - REND.x1) + REND.ny1b;
	REND.cnyb = CLAMP(REND.nyb, REND.ytop[x], REND.ybottom[x]);
	REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[REND.now.sectorno].npoints + 2];
	scaler_init(m, REND.ya, REND.cya, REND.yb, 0, 1023);
	vline2(m, x, REND.cya, REND.cnya - 1, REND.txtx); // Lower
	REND.ytop[x] = CLAMP(MAX(REND.cya, REND.cnya), REND.ytop[x], (int)WIN_H - 1);
	REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[REND.now.sectorno].npoints + 3];
	scaler_init(m, REND.ya, REND.cnyb + 1, REND.yb, 0, 1023);
	vline2(m, x, REND.cnyb + 1, REND.cyb, REND.txtx); // Upper
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
