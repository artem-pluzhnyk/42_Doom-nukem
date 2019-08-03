/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:09:42 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/17 17:38:29 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	render_all(t_main *m)
{
	unsigned	x;

	REND.head = REND.queue;
	REND.tail = REND.queue;
	REND.ytop = malloc(sizeof(int) * WIN_W);
	REND.ybottom = malloc(sizeof(int) * WIN_W);
	REND.rend_sect = malloc(sizeof(int) * m->num_s);
	x = -1;
	while (++x < WIN_W)
		REND.ybottom[x] = WIN_H - 1;
	x = -1;
	while (++x < m->num_s)
		REND.rend_sect[x] = 0;
	REND.head->sectorno = USER.sector;
	REND.head->sx1 = 0;
	REND.head->sx2 = WIN_W - 1;
	if (++REND.head == REND.queue + MAXQUEUE)
		REND.head = REND.queue;
	render_loop(m);
}

void	render_loop(t_main *m)
{
	while (REND.head != REND.tail)
	{
		REND.now = *REND.tail;
		if (++REND.tail == REND.queue + MAXQUEUE)
			REND.tail = REND.queue;
		if (REND.rend_sect[REND.now.sectorno] & 0x21)
			continue;
		++REND.rend_sect[REND.now.sectorno];
		REND.sect = &m->sectors[REND.now.sectorno];
		render_npoints(m);
	}
}

void	render_npoints(t_main *m)
{
	unsigned	s;

	s = -1;
	while (++s < REND.sect->npoints)
	{
		render_init1(m, s);
		if (REND.tz1 <= 0 && REND.tz2 <= 0)
			continue ;
		render_2(m);
		render_init3(m);
		if (REND.x1 >= REND.x2 || REND.x2 < REND.now.sx1 || REND.x1 > REND.now.sx2)
			continue ;
		render_init4(m, s);
		render_startend(m);
		render_last(m);
	}
	++REND.rend_sect[REND.now.sectorno];
}

void	render_init1(t_main *m, unsigned s)
{
	REND.vx1 = REND.sect->vertex[s + 0].x - USER.where.x;
	REND.vy1 = REND.sect->vertex[s + 0].y - USER.where.y;
	REND.vx2 = REND.sect->vertex[s + 1].x - USER.where.x;
	REND.vy2 = REND.sect->vertex[s + 1].y - USER.where.y;
	REND.pcos = USER.anglecos;
	REND.psin = USER.anglesin;
	REND.tx1 = REND.vx1 * REND.psin - REND.vy1 * REND.pcos;
	REND.tz1 = REND.vx1 * REND.pcos + REND.vy1 * REND.psin;
	REND.tx2 = REND.vx2 * REND.psin - REND.vy2 * REND.pcos;
	REND.tz2 = REND.vx2 * REND.pcos + REND.vy2 * REND.psin;
}
