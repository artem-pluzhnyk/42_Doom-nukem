/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_moving.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:45:47 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 18:52:10 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	event_moving(t_main *m)
{
	unsigned	s;

	if (MOVE.moving)
	{
		MOVE.px = USER.where.x;
		MOVE.py = USER.where.y;
		MOVE.dx = USER.velocity.x;
		MOVE.dy = USER.velocity.y;
		MOVE.sect = &MAP.sectors[USER.sector];
		s = -1;
		while (++s < MOVE.sect->npoints)
			event_moving2(m, s);
		move_player(m, MOVE.dx, MOVE.dy);
		MOVE.falling = 1;
	}
}

void	event_moving2(t_main *m, unsigned s)
{
	if (ISB(MOVE.px, MOVE.py, MOVE.px + MOVE.dx, MOVE.py + MOVE.dy,
		MOVE.sect->vertex[s + 0].x,
		MOVE.sect->vertex[s + 0].y, MOVE.sect->vertex[s + 1].x,
		MOVE.sect->vertex[s + 1].y)
		&& PS(MOVE.px + MOVE.dx, MOVE.py + MOVE.dy,
		MOVE.sect->vertex[s + 0].x, MOVE.sect->vertex[s + 0].y,
		MOVE.sect->vertex[s + 1].x, MOVE.sect->vertex[s + 1].y) < 0)
	{
		MOVE.hole_low = MOVE.sect->neighbors[s] < 0
		? 9e9 : MAX(MOVE.sect->floor,
		MAP.sectors[MOVE.sect->neighbors[s]].floor);
		MOVE.hole_high = MOVE.sect->neighbors[s] < 0
		? -9e9 : MIN(MOVE.sect->ceil,
		MAP.sectors[MOVE.sect->neighbors[s]].ceil);
		event_moving3(m, s);
	}
}

void	event_moving3(t_main *m, unsigned s)
{
	if (MOVE.hole_high < USER.where.z + HEAD_MARG
	|| MOVE.hole_low > USER.where.z - EYE_H + KNEE_H)
	{
		MOVE.xd = MOVE.sect->vertex[s + 1].x - MOVE.sect->vertex[s].x;
		MOVE.yd = MOVE.sect->vertex[s + 1].y - MOVE.sect->vertex[s].y;
		MOVE.dx = MOVE.xd * (MOVE.dx * MOVE.xd + MOVE.yd * MOVE.dy)
		/ (MOVE.xd * MOVE.xd + MOVE.yd * MOVE.yd);
		MOVE.dy = MOVE.yd * (MOVE.dx * MOVE.xd + MOVE.yd * MOVE.dy)
		/ (MOVE.xd * MOVE.xd + MOVE.yd * MOVE.yd);
		MOVE.moving = 0;
	}
}
