/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:45:47 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 20:06:25 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	render_init5(t_main *m, int x)
{
	REND.txtx2 = 0;
	REND.txtz2 = 0;
	REND.y = 0;
	REND.x = x;
	norm_kostyl1(m);
	while (++REND.y <= REND.ybottom[x])
	{
		if (REND.y >= REND.cya && REND.y <= REND.cyb)
		{
			REND.y = REND.cyb;
			continue ;
		}
		norm_kostyl3(m);
		if (REND.y < REND.cya)
			norm_kostyl2(m);
		else
			norm_kostyl4(m);
		((int*)SDL.sur->pixels)[REND.y * WIN_W + REND.x] = REND.pel;
	}
}

void	norm_kostyl1(t_main *m)
{
	REND.z = ((REND.x - REND.x1) * (REND.tz2 - REND.tz1) / (REND.x2 - REND.x1)
	+ REND.tz1) * 8;
	REND.ya = (REND.x - REND.x1) * (REND.y2a - REND.y1a) / (REND.x2 - REND.x1)
	+ REND.y1a;
	REND.yb = (REND.x - REND.x1) * (REND.y2b - REND.y1b) / (REND.x2 - REND.x1)
	+ REND.y1b;
	REND.cya = CLAMP(REND.ya, REND.ytop[REND.x], REND.ybottom[REND.x]);
	REND.cyb = CLAMP(REND.yb, REND.ytop[REND.x], REND.ybottom[REND.x]);
	REND.y = REND.ytop[REND.x] - 1;
}

void	norm_kostyl2(t_main *m)
{
	if (!(CFG.sky))
	{
		if (!(CFG.txtr))
			REND.txtr_id = SECT[REND.now.sectorno].texture[SECT
			[REND.now.sectorno].npoints + 1];
		else
			REND.txtr_id = 24;
		REND.pel = color_transoform(ft_get_pixel(SDL.texture[
			REND.txtr_id],
		REND.txtx2 % SDL.texture[REND.txtr_id]->w,
		REND.txtz2 % SDL.texture[REND.txtr_id]->h),
		percentage(255, 0, REND.z));
	}
	else
		REND.pel = ((int*)SDL.sur->pixels)[REND.y * WIN_W + REND.x];
}

void	norm_kostyl3(t_main *m)
{
	REND.hei = REND.y < REND.cya ? REND.yceil : REND.yfloor;
	REND.mapx = 0;
	REND.mapz = 0;
	coord_to_texture(m, REND.x, REND.y);
	REND.txtx2 = REND.mapx * 256;
	REND.txtz2 = REND.mapz * 256;
}

void	norm_kostyl4(t_main *m)
{
	if (!(CFG.txtr))
		REND.txtr_id = SECT[REND.now.sectorno].texture[SECT[
			REND.now.sectorno].npoints];
	else
		REND.txtr_id = 25;
	REND.pel = color_transoform(ft_get_pixel(SDL.texture[REND.txtr_id],
	REND.txtx2 % SDL.texture[REND.txtr_id]->w,
	REND.txtz2 % SDL.texture[REND.txtr_id]->h),
	percentage(255, 0, REND.z));
}
