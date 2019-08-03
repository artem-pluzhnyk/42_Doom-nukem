/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:04:29 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/31 18:20:16 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	events(t_main *m)
{
	MOV.eyeheight = MOV.ducking ? DUCK_H : EYE_H;
	MOV.ground = !MOV.falling;
	if (MOV.falling)
		event_falling(m);
	if (MOV.moving)
		event_moving(m);
	mouse_rotation(m);
}

void	event_falling(t_main *m)
{
	USER.velocity.z -= 0.05f;
	MOV.nextz = USER.where.z + USER.velocity.z;
	if (USER.velocity.z < 0 && MOV.nextz < m->sectors[USER.sector].floor + MOV.eyeheight)
	{
		USER.where.z = m->sectors[USER.sector].floor + MOV.eyeheight;
		USER.velocity.z = 0;
		MOV.falling = 0;
		MOV.ground  = 1;
	}
	else if (USER.velocity.z > 0 && MOV.nextz > m->sectors[USER.sector].ceil)
	{
		USER.velocity.z = 0;
		MOV.falling = 1;
	}
	if (MOV.falling)
	{
		USER.where.z = USER.velocity.z;
		MOV.moving = 1;
	}
}

void	event_moving(t_main *m)
{
	unsigned	s;

	s = -1;
	if(MOV.moving)
	{
		MOV.px = USER.where.x;
		MOV.py = USER.where.y;
		MOV.dx = USER.velocity.x;
		MOV.dy = USER.velocity.y;
		MOV.sect = &m->sectors[USER.sector];
		MOV.vert = MOV.sect->vertex;
		while (++s < MOV.sect->npoints)
			if (ISB(MOV.px, MOV.py, MOV.px + MOV.dx, MOV.py + MOV.dy, MOV.vert[s + 0].x,
			MOV.vert[s + 0].y, MOV.vert[s + 1].x, MOV.vert[s + 1].y)
			&& PS(MOV.px + MOV.dx, MOV.py + MOV.dy, MOV.vert[s + 0].x, MOV.vert[s + 0].y,
			MOV.vert[s + 1].x, MOV.vert[s + 1].y) < 0)
			{
				MOV.hole_low = MOV.sect->neighbors[s] < 0 ?  9e9 : MAX(MOV.sect->floor,
				m->sectors[MOV.sect->neighbors[s]].floor);
				MOV.hole_high = MOV.sect->neighbors[s] < 0 ? -9e9 : MIN(MOV.sect->ceil,
				m->sectors[MOV.sect->neighbors[s]].ceil);
				if(MOV.hole_high < USER.where.z + HEAD_MARG
				|| MOV.hole_low  > USER.where.z - EYE_H + KNEE_H)
				{
					MOV.xd = MOV.vert[s + 1].x - MOV.vert[s + 0].x;
					MOV.yd = MOV.vert[s + 1].y - MOV.vert[s + 0].y;
					MOV.dx = MOV.xd * (MOV.dx * MOV.xd + MOV.yd * MOV.dy)
					/ (MOV.xd * MOV.xd + MOV.yd * MOV.yd);
					MOV.dy = MOV.yd * (MOV.dx * MOV.xd + MOV.yd * MOV.dy)
					/ (MOV.xd * MOV.xd + MOV.yd * MOV.yd);
					MOV.moving = 0;
				}
			}
			move_player(m, MOV.dx, MOV.dy);
			MOV.falling = 1;
		}
}

void	move_player(t_main *m, float dx, float dy)
{
	unsigned	s;
	float		px;
	float		py;
	t_sector	*sect;
	t_xy		*vert;

	s = -1;
	px = USER.where.x;
	py = USER.where.y;
	sect = &m->sectors[USER.sector];
	vert = sect->vertex;
	while (++s < sect->npoints)
		if (sect->neighbors[s] >= 0
		&& ISB(px, py, px + dx, py + dy, vert[s + 0].x, vert[s + 0].y,
		vert[s + 1].x, vert[s + 1].y)
		&& PS(px + dx, py + dy, vert[s + 0].x, vert[s + 0].y, vert[s + 1].x,
		vert[s + 1].y) < 0)
		{
			USER.sector = sect->neighbors[s];
			break ;
		}
	USER.where.x += dx;
	USER.where.y += dy;
	USER.anglesin = sinf(USER.angle);
	USER.anglecos = cosf(USER.angle);
}
