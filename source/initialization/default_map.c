/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 16:29:48 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/03 15:25:13 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"


void	create_map(t_main *m, char *file)
{
	int		fd;

	fd = 0;
	fd = open(file, O_CREAT | O_RDWR);
	default_vertex(m, fd);
	default_sector(m, fd);
	default_player(m, fd);
}

void	default_vertex(t_main *m, int fd)
{
	m->num_v = 8;
	write(fd, &m->num_v, sizeof(int));
	m->vert = malloc(sizeof(t_xy) * m->num_v);
	m->vert[0].y = 0;
	m->vert[0].x = 0;
	m->vert[1].y = 0;
	m->vert[1].x = 50;
	m->vert[2].y = 50;
	m->vert[2].x = 0;
	m->vert[3].y = 50;
	m->vert[3].x = 20;
	m->vert[4].y = 50;
	m->vert[4].x = 30;
	m->vert[5].y = 50;
	m->vert[5].x = 50;
	m->vert[6].y = 80;
	m->vert[6].x = 0;
	m->vert[7].y = 80;
	m->vert[7].x = 50;
	write(fd, m->vert, sizeof(t_xy) * m->num_v);
}

void	default_sector(t_main *m, int fd)
{
	m->num_s = 2;
	write(fd, &m->num_s, sizeof(int));
	SECT = malloc(sizeof(t_sector) * m->num_s);
	SECT[0].floor = 0;
	SECT[0].ceil = 20;
	SECT[0].npoints = 6;
	SECT[0].neighbors = malloc(sizeof(signed char) * SECT[0].npoints);
	SECT[0].neighbors[0] = -1;
	SECT[0].neighbors[1] = -1;
	SECT[0].neighbors[2] = -1;
	SECT[0].neighbors[3] = -1;
	SECT[0].neighbors[4] = 1;
	SECT[0].neighbors[5] = -1;
	SECT[0].vertex = malloc(sizeof(t_xy) * (SECT[0].npoints + 1));
	SECT[0].vertex[1] = m->vert[0];
	SECT[0].vertex[2] = m->vert[1];
	SECT[0].vertex[3] = m->vert[5];
	SECT[0].vertex[4] = m->vert[4];
	SECT[0].vertex[5] = m->vert[3];
	SECT[0].vertex[6] = m->vert[2];
	SECT[0].vertex[0] = SECT[0].vertex[6];
	SECT[1].floor = 2;
	SECT[1].ceil = 15;
	SECT[1].npoints = 6;
	SECT[1].neighbors = malloc(sizeof(signed char) * SECT[1].npoints);
	SECT[1].neighbors[0] = -1;
	SECT[1].neighbors[1] = -1;
	SECT[1].neighbors[2] = 0;
	SECT[1].neighbors[3] = -1;
	SECT[1].neighbors[4] = -1;
	SECT[1].neighbors[5] = -1;
	SECT[1].vertex = malloc(sizeof(t_xy) * (SECT[1].npoints + 1));
	SECT[1].vertex[1] = m->vert[2];
	SECT[1].vertex[2] = m->vert[3];
	SECT[1].vertex[3] = m->vert[4];
	SECT[1].vertex[4] = m->vert[5];
	SECT[1].vertex[5] = m->vert[7];
	SECT[1].vertex[6] = m->vert[6];
	SECT[1].vertex[0] = SECT[1].vertex[6];
	write(fd, SECT, sizeof(t_sector) * m->num_s);
	write(fd, SECT[0].neighbors, sizeof(signed char) * SECT[0].npoints);
	write(fd, SECT[0].vertex, sizeof(t_xy) * (SECT[0].npoints + 1));
	write(fd, SECT[1].neighbors, sizeof(signed char) * SECT[1].npoints);
	write(fd, SECT[1].vertex, sizeof(t_xy) * (SECT[1].npoints + 1));
}

void	default_player(t_main *m, int fd)
{
	USER.where.x = 25;
	USER.where.y = 15;
	USER.velocity.x = 0;
	USER.velocity.y = 0;
	USER.velocity.z = 0;
	USER.angle = 0;
	USER.anglesin = 0;
	USER.anglecos = 0;
	USER.yaw = 0;
	USER.sector = 0;
	USER.where.z = m->sectors[USER.sector].floor + EYE_H;
	write(fd, &USER, sizeof(t_player));
}
