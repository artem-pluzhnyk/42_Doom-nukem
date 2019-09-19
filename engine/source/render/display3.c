/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:09:42 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/18 19:31:11 by apluzhni         ###   ########.fr       */
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
			vline(m, x, REND.cya, REND.cyb, REND.txtx); // Walls
		}
	}
}

void	render_init5(t_main *m, int x)
{
	int			y;
	unsigned	txtx;
	unsigned	txtz;

	REND.z = ((x - REND.x1) * (REND.tz2 - REND.tz1) / (REND.x2 - REND.x1) + REND.tz1) * 8;
	REND.ya = (x - REND.x1) * (REND.y2a - REND.y1a) / (REND.x2 - REND.x1) + REND.y1a;
	REND.yb = (x - REND.x1) * (REND.y2b - REND.y1b) / (REND.x2 - REND.x1) + REND.y1b;
	REND.cya = CLAMP(REND.ya, REND.ytop[x], REND.ybottom[x]);
	REND.cyb = CLAMP(REND.yb, REND.ytop[x], REND.ybottom[x]);
	y = REND.ytop[x] - 1;
	while (++y <= REND.ybottom[x])
	{
		if(y >= REND.cya && y <= REND.cyb)
		{
			y = REND.cyb;
			continue ;
		}
		REND.hei = y < REND.cya ? REND.yceil : REND.yfloor;
		REND.mapx = 0;
		REND.mapz = 0;
		coord_to_texture(m, x, y);
		txtx = REND.mapx * 256;
		txtz = REND.mapz * 256;
		if (y < REND.cya)
		{
			if (!(CFG.sky))
			{
				REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[REND.now.sectorno].npoints + 1]; // Ceiling
				REND.pel = color_transoform(ft_get_pixel(SDL.texture[REND.txtr_id],
				txtx % SDL.texture[REND.txtr_id]->w, txtz % SDL.texture[REND.txtr_id]->h),
				percentage(255, 0, REND.z));
			}
			else
				REND.pel = ((int*) SDL.sur->pixels)[y * WIN_W + x];
		}
		else
		{
			REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[REND.now.sectorno].npoints]; // Floor
			REND.pel = color_transoform(ft_get_pixel(SDL.texture[REND.txtr_id],
			txtx % SDL.texture[REND.txtr_id]->w, txtz % SDL.texture[REND.txtr_id]->h),
			percentage(255, 0, REND.z));
		}
		((int*) SDL.sur->pixels)[y * WIN_W + x] = REND.pel;
	}
}

void	render_init6(t_main *m, int x)
{
	REND.nya = (x - REND.x1) * (REND.ny2a - REND.ny1a) / (REND.x2 - REND.x1) + REND.ny1a;
	REND.cnya = CLAMP(REND.nya, REND.ytop[x], REND.ybottom[x]);
	REND.nyb = (x - REND.x1) * (REND.ny2b - REND.ny1b) / (REND.x2 - REND.x1) + REND.ny1b;
	REND.cnyb = CLAMP(REND.nyb, REND.ytop[x], REND.ybottom[x]);
	REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[REND.now.sectorno].npoints + 2];
	scaler_init(m, REND.ya, REND.cya, REND.yb, 0, 1023);
	vline(m, x, REND.cya, REND.cnya - 1, REND.txtx); // Lower
	REND.ytop[x] = CLAMP(MAX(REND.cya, REND.cnya), REND.ytop[x], (int)WIN_H - 1);
	REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[REND.now.sectorno].npoints + 3];
	scaler_init(m, REND.ya, REND.cnyb + 1, REND.yb, 0, 1023);
	vline(m, x, REND.cnyb + 1, REND.cyb, REND.txtx); // Upper
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

void	coord_to_texture(t_main *m, int x, int y)
{
	float	rtx;
	float	rtz;

	REND.mapz = REND.hei * WIN_H * VFOV  / ((WIN_H / 2 - (float)y) - USER.yaw * WIN_H * VFOV);
	REND.mapx = REND.mapz * (WIN_W / 2 - (float)x) / (WIN_W * HFOV);
	rtx = REND.mapz * REND.pcos + REND.mapx * REND.psin;
	rtz = REND.mapz * REND.psin - REND.mapx * REND.pcos;
	REND.mapx = rtx + USER.where.x;
	REND.mapz = rtz + USER.where.y;
}
