/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:09:42 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/07 19:55:23 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	render_2(t_main *m)
{
	if (REND.tz1 <= 0 || REND.tz2 <= 0)
	{
		render_init2(m);
		REND.org1.x = REND.tx1;
		REND.org1.y = REND.tz1;
		REND.org2.x = REND.tx2;
		REND.org2.y = REND.tz2;
		if (REND.tz1 < 1e-4f)
		{
			if (REND.i1.y > 0)
			{
				REND.tx1 = REND.i1.x;
				REND.tz1 = REND.i1.y;
			}
			else
			{
				REND.tx1 = REND.i2.x;
				REND.tz1 = REND.i2.y;
			}
		}
		if (REND.tz2 < 1e-4f)
		{
			if (REND.i1.y > 0)
			{
				REND.tx2 = REND.i1.x;
				REND.tz2 = REND.i1.y;
			}
			else
			{
				REND.tx2 = REND.i2.x;
				REND.tz2 = REND.i2.y;
			}
		}
		if (fabsf(REND.tx2 - REND.tx1) > fabsf(REND.tz2 - REND.tz1))
		{
			REND.u0 = (REND.tx1 - REND.org1.x) * 1023 / (REND.org2.x - REND.org1.x);
			REND.u1 = (REND.tx2 - REND.org1.x) * 1023 / (REND.org2.x - REND.org1.x);
		}
		else
		{
			REND.u0 = (REND.tz1 - REND.org1.y) * 1023 / (REND.org2.y - REND.org1.y);
			REND.u1 = (REND.tz2 - REND.org1.y) * 1023 / (REND.org2.y - REND.org1.y);
		}
	}
}

void	render_init2(t_main *m)
{
		IS.x1 = REND.tx1;
		IS.y1 = REND.tz1;
		IS.x2 = REND.tx2;
		IS.y2 = REND.tz2;
		IS.x3 = -1e-5f;
		IS.y3 = 1e-4f;
		IS.x4 = -20.f;
		IS.y4 = 5;
		REND.i1 = intersect(m);
		IS.x3 = 1e-5f;
		IS.x4 = 20.f;
		REND.i2 = intersect(m);
}

void	render_init3(t_main *m)
{
	REND.xscale1 = H_FOV / REND.tz1;
	REND.yscale1 = V_FOV / REND.tz1;
	REND.x1 = WIN_W / 2 - (int)(REND.tx1 * REND.xscale1);
	REND.xscale2 = H_FOV / REND.tz2;
	REND.yscale2 = V_FOV / REND.tz2;
	REND.x2 = WIN_W / 2 - (int)(REND.tx2 * REND.xscale2);
}

void	render_init4(t_main *m, unsigned s)
{
	REND.yceil = REND.sect->ceil  - USER.where.z;
	REND.yfloor = REND.sect->floor - USER.where.z;
	REND.neighbor = REND.sect->neighbors[s];
	REND.nyceil = 0;
	REND.nyfloor = 0;
	if (REND.neighbor >= 0)
	{
		REND.nyceil  = SECT[REND.neighbor].ceil  - USER.where.z;
		REND.nyfloor = SECT[REND.neighbor].floor - USER.where.z;
	}
	REND.y1a  = WIN_H / 2 - (int)(YAW(REND.yceil, REND.tz1) * REND.yscale1);
	REND.y1b = WIN_H / 2 - (int)(YAW(REND.yfloor, REND.tz1) * REND.yscale1);
	REND.y2a  = WIN_H / 2 - (int)(YAW(REND.yceil, REND.tz2) * REND.yscale2);
	REND.y2b = WIN_H / 2 - (int)(YAW(REND.yfloor, REND.tz2) * REND.yscale2);
	REND.ny1a = WIN_H / 2 - (int)(YAW(REND.nyceil, REND.tz1) * REND.yscale1);
	REND.ny1b = WIN_H / 2 - (int)(YAW(REND.nyfloor, REND.tz1) * REND.yscale1);
	REND.ny2a = WIN_H / 2 - (int)(YAW(REND.nyceil, REND.tz2) * REND.yscale2);
	REND.ny2b = WIN_H / 2 - (int)(YAW(REND.nyfloor, REND.tz2) * REND.yscale2);
	REND.beginx = MAX(REND.x1, REND.now.sx1);
	REND.endx = MIN(REND.x2, REND.now.sx2);
}
