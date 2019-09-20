/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:23:43 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 15:37:28 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	create_map(t_main *m, char *file)
{
	m->fd = open(file, O_CREAT | O_RDWR);
	default_vertex(m);
	default_sector(m);
	default_player(m);
}

void	default_vertex(t_main *m)
{
	MAP.num_v = 6;
	write(m->fd, &MAP.num_v, sizeof(int));
	MAP.vert = malloc(sizeof(t_xy) * MAP.num_v);
	MAP.vert[0].y = 0;
	MAP.vert[0].x = 0;
	MAP.vert[1].y = 0;
	MAP.vert[1].x = 15;
	MAP.vert[2].y = 10;
	MAP.vert[2].x = 0;
	MAP.vert[3].y = 10;
	MAP.vert[3].x = 15;
	MAP.vert[4].y = 20;
	MAP.vert[4].x = 0;
	MAP.vert[5].y = 20;
	MAP.vert[5].x = 15;
	write(m->fd, MAP.vert, sizeof(t_xy) * MAP.num_v);
}

void	default_sector(t_main *m)
{
	int		i;

	i = 0;
	MAP.num_s = 2;
	write(m->fd, &MAP.num_s, sizeof(int));
	SECT = malloc(sizeof(t_sector) * MAP.num_s);
	SECT[0].floor = 0;
	SECT[0].ceil = 20;
	SECT[0].npoints = 4;
	SECT[0].neighbors = malloc(sizeof(signed char) * SECT[0].npoints);
	SECT[0].neighbors[0] = -1;
	SECT[0].neighbors[1] = -1;
	SECT[0].neighbors[2] = -1;
	SECT[0].neighbors[3] = 1;
	SECT[0].vertex = malloc(sizeof(t_xy) * (SECT[0].npoints + 1));
	SECT[0].vertex[1] = MAP.vert[0];
	SECT[0].vertex[2] = MAP.vert[1];
	SECT[0].vertex[3] = MAP.vert[3];
	SECT[0].vertex[4] = MAP.vert[2];
	SECT[0].vertex[0] = SECT[0].vertex[4];
	SECT[0].texture = malloc(sizeof(int) * (SECT[0].npoints + 4));
	SECT[0].texture[0] = 13;
	SECT[0].texture[1] = 13;
	SECT[0].texture[2] = 13;
	SECT[0].texture[3] = 13;
	SECT[0].texture[4] = 12;
	SECT[0].texture[5] = 14;
	SECT[0].texture[6] = 7;
	SECT[0].texture[7] = 8;
	SECT[0].gas = 0;
	SECT[0].gun = 0;
	SECT[1].floor = 2;
	SECT[1].ceil = 15;
	SECT[1].npoints = 4;
	SECT[1].neighbors = malloc(sizeof(signed char) * SECT[1].npoints);
	SECT[1].neighbors[0] = -1;
	SECT[1].neighbors[1] = 0;
	SECT[1].neighbors[2] = -1;
	SECT[1].neighbors[3] = -1;
	SECT[1].vertex = malloc(sizeof(t_xy) * (SECT[1].npoints + 1));
	SECT[1].vertex[1] = MAP.vert[2];
	SECT[1].vertex[2] = MAP.vert[3];
	SECT[1].vertex[3] = MAP.vert[5];
	SECT[1].vertex[4] = MAP.vert[4];
	SECT[1].vertex[0] = SECT[1].vertex[4];
	SECT[1].texture = malloc(sizeof(int) * (SECT[1].npoints + 4));
	SECT[1].texture[0] = 13;
	SECT[1].texture[1] = 13;
	SECT[1].texture[2] = 13;
	SECT[1].texture[3] = 13;
	SECT[1].texture[4] = 12;
	SECT[1].texture[5] = 14;
	SECT[1].texture[6] = 7;
	SECT[1].texture[7] = 8;
	SECT[1].gas = 1;
	SECT[1].gun = 1;
	write(m->fd, SECT, sizeof(t_sector) * MAP.num_s);
	while (++i < (int)MAP.num_s)
	{
		write(m->fd, SECT[i].neighbors, sizeof(signed char) * SECT[i].npoints);
		write(m->fd, SECT[i].vertex, sizeof(t_xy) * (SECT[i].npoints + 1));
		write(m->fd, SECT[i].texture, sizeof(int) * (SECT[i].npoints + 4));
	}
}

void	default_player(t_main *m)
{
	USER.where.x = 5;
	USER.where.y = 5;
	USER.velocity.x = 0;
	USER.velocity.y = 0;
	USER.velocity.z = 0;
	USER.angle = 0;
	USER.anglesin = 0;
	USER.anglecos = 0;
	USER.yaw = 0;
	USER.sector = 0;
	USER.where.z = MAP.sectors[USER.sector].floor + EYE_H;
	USER.speed = 0.3f;
	USER.health = 100;
	USER.armor = 125;
	USER.spawn_sect = 0;
	USER.spawn.x = 5;
	USER.spawn.y = 5;
	USER.spawn.z = MAP.sectors[USER.spawn_sect].floor + EYE_H;
	USER.gun = 0;
	write(m->fd, &USER, sizeof(t_player));
}
