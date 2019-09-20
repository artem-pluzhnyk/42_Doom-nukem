/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:10:27 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 18:55:32 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	events(t_main *m)
{
	MOVE.eyeheight = MOVE.ducking ? DUCK_H : EYE_H;
	if (CFG.fly)
		MOVE.ground = !MOVE.falling;
	if (MOVE.falling)
		event_falling(m);
	if (MOVE.moving)
		event_moving(m);
	mouse_rotation(m);
}

void	move_player(t_main *m, float dx, float dy)
{
	unsigned	s;
	float		px;
	float		py;
	t_sector	*sect;
	t_xy		*vert;

	px = USER.where.x;
	py = USER.where.y;
	sect = &MAP.sectors[USER.sector];
	vert = sect->vertex;
	s = -1;
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

void	event_falling(t_main *m)
{
	USER.velocity.z -= 0.05f;
	MOVE.nextz = USER.where.z + USER.velocity.z;
	if (USER.velocity.z < 0 && MOVE.nextz <
		MAP.sectors[USER.sector].floor + MOVE.eyeheight)
	{
		USER.where.z = MAP.sectors[USER.sector].floor + MOVE.eyeheight;
		USER.velocity.z = 0;
		MOVE.falling = 0;
		MOVE.ground = 1;
	}
	else if (USER.velocity.z > 0 && MOVE.nextz > MAP.sectors[USER.sector].ceil)
	{
		USER.velocity.z = 0;
		MOVE.falling = 1;
	}
	if (MOVE.falling)
	{
		USER.where.z += USER.velocity.z;
		MOVE.moving = 1;
	}
}
