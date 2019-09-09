/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:23:43 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/09 19:18:26 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	create_map(t_main *m, char *file)
{
	m->fd = open(file, O_CREAT | O_RDWR);
	default_vertex(m);
	default_sector(m);
	default_player(m);
	default_poster(m);
	default_sprite(m);
}

void	default_vertex(t_main *m)
{
	MAP.num_v = 8;	// number of points (vert)
	write(m->fd, &MAP.num_v, sizeof(int));
	MAP.vert = malloc(sizeof(t_xy) * MAP.num_v);	// vertex
	MAP.vert[0].y = 0;
	MAP.vert[0].x = 0;
	MAP.vert[1].y = 0;
	MAP.vert[1].x = 15;
	MAP.vert[2].y = 10;
	MAP.vert[2].x = 0;
	MAP.vert[3].y = 10;
	MAP.vert[3].x = 5;
	MAP.vert[4].y = 10;
	MAP.vert[4].x = 10;
	MAP.vert[5].y = 10;
	MAP.vert[5].x = 15;
	MAP.vert[6].y = 20;
	MAP.vert[6].x = 0;
	MAP.vert[7].y = 20;
	MAP.vert[7].x = 15;
	write(m->fd, MAP.vert, sizeof(t_xy) * MAP.num_v);
}

void	default_sector(t_main *m)
{
	MAP.num_s = 2;	// number of sectors
	write(m->fd, &MAP.num_s, sizeof(int));
	SECT = malloc(sizeof(t_sector) * MAP.num_s);

	SECT[0].floor = 0;
	SECT[0].ceil = 20;
	SECT[0].npoints = 6;	// number of walls (and points)
	SECT[0].neighbors = malloc(sizeof(signed char) * SECT[0].npoints);	// neighbors sectors
	SECT[0].neighbors[0] = -1;
	SECT[0].neighbors[1] = -1;
	SECT[0].neighbors[2] = -1;
	SECT[0].neighbors[3] = -1;
	SECT[0].neighbors[4] = 1;
	SECT[0].neighbors[5] = -1;
	SECT[0].vertex = malloc(sizeof(t_xy) * (SECT[0].npoints + 1));	// walls (must be in same order)
	SECT[0].vertex[1] = MAP.vert[0];
	SECT[0].vertex[2] = MAP.vert[1];
	SECT[0].vertex[3] = MAP.vert[5];
	SECT[0].vertex[4] = MAP.vert[4];
	SECT[0].vertex[5] = MAP.vert[3];
	SECT[0].vertex[6] = MAP.vert[2];
	SECT[0].vertex[0] = SECT[0].vertex[6];
	SECT[0].texture = malloc(sizeof(int) * (SECT[0].npoints + 4));	// id of texture fot every wall (in same order, like vertex) and other
	SECT[0].texture[0] = 13;
	SECT[0].texture[1] = 13;
	SECT[0].texture[2] = 13;
	SECT[0].texture[3] = 13;
	SECT[0].texture[4] = -1;
	SECT[0].texture[5] = 13;
	SECT[0].texture[6] = 12; // floor
	SECT[0].texture[7] = 14; // ceiling
	SECT[0].texture[8] = 7; // lower
	SECT[0].texture[9] = 8; // upper
	SECT[0].gas = 0;

	SECT[1].floor = 2;	// next sector
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
	SECT[1].vertex[1] = MAP.vert[2];
	SECT[1].vertex[2] = MAP.vert[3];
	SECT[1].vertex[3] = MAP.vert[4];
	SECT[1].vertex[4] = MAP.vert[5];
	SECT[1].vertex[5] = MAP.vert[7];
	SECT[1].vertex[6] = MAP.vert[6];
	SECT[1].vertex[0] = SECT[1].vertex[6];
	SECT[1].texture = malloc(sizeof(int) * (SECT[1].npoints + 4));
	SECT[1].texture[0] = 13;
	SECT[1].texture[1] = 13;
	SECT[1].texture[2] = -1;
	SECT[1].texture[3] = 13;
	SECT[1].texture[4] = 13;
	SECT[1].texture[5] = 13;
	SECT[1].texture[6] = 12; // floor
	SECT[1].texture[7] = 14; // ceiling
	SECT[1].texture[8] = 7; // lower
	SECT[1].texture[9] = 8; // upper
	SECT[1].gas = 1;

	write(m->fd, SECT, sizeof(t_sector) * MAP.num_s);	// write all data about sector

	write(m->fd, SECT[0].neighbors, sizeof(signed char) * SECT[0].npoints);
	write(m->fd, SECT[0].vertex, sizeof(t_xy) * (SECT[0].npoints + 1));
	write(m->fd, SECT[0].texture, sizeof(int) * (SECT[0].npoints + 4));

	write(m->fd, SECT[1].neighbors, sizeof(signed char) * SECT[1].npoints);
	write(m->fd, SECT[1].vertex, sizeof(t_xy) * (SECT[1].npoints + 1));
	write(m->fd, SECT[1].texture, sizeof(int) * (SECT[1].npoints + 4));
}

void	default_player(t_main *m)
{
	USER.where.x = 5;	// player position
	USER.where.y = 5;
	USER.velocity.x = 0;	// must be zero
	USER.velocity.y = 0;	// must be zero
	USER.velocity.z = 0;	// must be zero
	USER.angle = 0;	// must be zero (player rotation)
	USER.anglesin = 0;	// must be zero
	USER.anglecos = 0;	// must be zero
	USER.yaw = 0;	// must be zero
	USER.sector = 0;	// sector for spawn player
	USER.where.z = MAP.sectors[USER.sector].floor + EYE_H;	// player position (height)
	USER.speed = 0.3f;
	USER.health = 90;
	USER.armor = 75;
	write(m->fd, &USER, sizeof(t_player));
}

void	default_poster(t_main *m)	// unused
{
	MAP.num_poster = 1;
	write(m->fd, &MAP.num_poster, sizeof(unsigned));
	PIC = malloc(sizeof(t_poster) * MAP.num_poster);
	PIC[0].poz.x = 10;
	PIC[0].poz.y = 50;
	PIC[0].texture = 10;
	write(m->fd, PIC, sizeof(t_poster) * MAP.num_poster);
}

void	default_sprite(t_main *m)	// unused
{
	MAP.num_sprite = 1;
	write(m->fd, &MAP.num_sprite, sizeof(unsigned));
	OBJ = malloc(sizeof(t_sprite) * MAP.num_sprite);
	OBJ[0].poz.x = 40;
	OBJ[0].poz.y = 40;
	OBJ[0].texture = 11;
	write(m->fd, OBJ, sizeof(t_sprite) * MAP.num_sprite);
}
