/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:10:27 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/21 17:21:49 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	events(t_main *m)
{
	MOVE.eyeheight = MOVE.ducking ? DUCK_H : EYE_H;
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
	if (USER.velocity.z < 0 && MOVE.nextz < MAP.sectors[USER.sector].floor + MOVE.eyeheight)
	{
		USER.where.z = MAP.sectors[USER.sector].floor + MOVE.eyeheight;
		USER.velocity.z = 0;
		MOVE.falling = 0;
		MOVE.ground  = 1;
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

void	event_moving(t_main *m)
{
	unsigned	s;

	if(MOVE.moving)
	{
		MOVE.px = USER.where.x;
		MOVE.py = USER.where.y;
		MOVE.dx = USER.velocity.x;
		MOVE.dy = USER.velocity.y;
		MOVE.sect = &MAP.sectors[USER.sector];
		s = -1;
		while (++s < MOVE.sect->npoints)
			if (ISB(MOVE.px, MOVE.py, MOVE.px + MOVE.dx, MOVE.py + MOVE.dy, MOVE.sect->vertex[s + 0].x,
			MOVE.sect->vertex[s + 0].y, MOVE.sect->vertex[s + 1].x, MOVE.sect->vertex[s + 1].y)
			&& PS(MOVE.px + MOVE.dx, MOVE.py + MOVE.dy, MOVE.sect->vertex[s + 0].x, MOVE.sect->vertex[s + 0].y,
			MOVE.sect->vertex[s + 1].x, MOVE.sect->vertex[s + 1].y) < 0)
			{
				MOVE.hole_low = MOVE.sect->neighbors[s] < 0 ?  9e9 : MAX(MOVE.sect->floor,
				MAP.sectors[MOVE.sect->neighbors[s]].floor);
				MOVE.hole_high = MOVE.sect->neighbors[s] < 0 ? -9e9 : MIN(MOVE.sect->ceil,
				MAP.sectors[MOVE.sect->neighbors[s]].ceil);
				if(MOVE.hole_high < USER.where.z + HEAD_MARG
				|| MOVE.hole_low  > USER.where.z - EYE_H + KNEE_H)
				{
					MOVE.xd = MOVE.sect->vertex[s + 1].x - MOVE.sect->vertex[s].x;
					MOVE.yd = MOVE.sect->vertex[s + 1].y - MOVE.sect->vertex[s].y;
					USER.velocity.x = MOVE.xd * (MOVE.dx * MOVE.xd + MOVE.yd * MOVE.dy)
					/ (MOVE.xd * MOVE.xd + MOVE.yd * MOVE.yd);
					USER.velocity.y = MOVE.yd * (MOVE.dx * MOVE.xd + MOVE.yd * MOVE.dy)
					/ (MOVE.xd * MOVE.xd + MOVE.yd * MOVE.yd);
					MOVE.moving = 0;
				}
			}
			move_player(m, MOVE.dx, MOVE.dy);
			MOVE.falling = 1;
		}
}

void	mouse_rotation(t_main *m)
{
	int		x;
	int		y;
	double	old_dir_x;
	double	old_plane_x;

	SDL_GetRelativeMouseState(&x,&y);
	USER.angle += x * 0.03f;
	MOVE.yaw = CLAMP(MOVE.yaw + y * 0.05f, -5, 5);
	USER.yaw = MOVE.yaw - USER.velocity.z * 0.5f;
	move_player(m, 0,0);
	MOVE.move_vec[0] = 0.f;
	MOVE.move_vec[1] = 0.f;

	old_dir_x = SREND.dir_x;
	SREND.dir_x = SREND.dir_x * cos(0.01f) - SREND.dir_y * sin(0.01f);
	SREND.dir_y = old_dir_x * sin(0.01f) + SREND.dir_y * cos(0.01f);
	old_plane_x = SREND.plane_x;
	SREND.plane_x = SREND.plane_x * cos(0.01f) - SREND.plane_y * sin(0.01f);
	SREND.plane_y = old_plane_x * sin(0.01f) + SREND.plane_y * cos(0.01f);

	if (MOVE.wsad[0])
	{
		MOVE.move_vec[0] += USER.anglecos * 0.2f;
		MOVE.move_vec[1] += USER.anglesin * 0.2f;
	}
	if (MOVE.wsad[1])
	{
		MOVE.move_vec[0] -= USER.anglecos * 0.2f;
		MOVE.move_vec[1] -= USER.anglesin * 0.2f;
	}
	if (MOVE.wsad[2])
	{
		MOVE.move_vec[0] += USER.anglesin * 0.2f;
		MOVE.move_vec[1] -= USER.anglecos * 0.2f;
	}
	if (MOVE.wsad[3])
	{
		MOVE.move_vec[0] -= USER.anglesin * 0.2f;
		MOVE.move_vec[1] += USER.anglecos * 0.2f;
	}

	MOVE.pushing = MOVE.wsad[0] || MOVE.wsad[1] || MOVE.wsad[2] || MOVE.wsad[3];
	MOVE.acceleration = MOVE.pushing ? 0.4 : 0.2;
	USER.velocity.x = USER.velocity.x * (1 - MOVE.acceleration) + MOVE.move_vec[0] * MOVE.acceleration;
	USER.velocity.y = USER.velocity.y * (1 - MOVE.acceleration) + MOVE.move_vec[1] * MOVE.acceleration;

	if (MOVE.pushing)
		MOVE.moving = 1;
	SDL_Delay(10);
}
