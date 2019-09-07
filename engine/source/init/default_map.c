/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:23:43 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/05 13:04:17 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	create_map(t_main *m, char *file)
{
	int		fd;

	fd = open(file, O_CREAT | O_RDWR);
	default_vertex(m, fd);
	default_sector(m, fd);
	default_player(m, fd);
	default_poster(m, fd);
	default_sprite(m, fd);
}

void	default_vertex(t_main *m, int fd)
{
	MAP.num_v = 8;
	write(fd, &MAP.num_v, sizeof(int));
	MAP.vert = malloc(sizeof(t_xy) * MAP.num_v);
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
	write(fd, MAP.vert, sizeof(t_xy) * MAP.num_v);
}

void	default_sector(t_main *m, int fd)
{
	MAP.num_s = 2;
	write(fd, &MAP.num_s, sizeof(int));
	SECT = malloc(sizeof(t_sector) * MAP.num_s);

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
	SECT[0].vertex[1] = MAP.vert[0];
	SECT[0].vertex[2] = MAP.vert[1];
	SECT[0].vertex[3] = MAP.vert[5];
	SECT[0].vertex[4] = MAP.vert[4];
	SECT[0].vertex[5] = MAP.vert[3];
	SECT[0].vertex[6] = MAP.vert[2];
	SECT[0].vertex[0] = SECT[0].vertex[6];
	SECT[0].texture = malloc(sizeof(int) * (SECT[0].npoints + 4));
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

	write(fd, SECT, sizeof(t_sector) * MAP.num_s);

	write(fd, SECT[0].neighbors, sizeof(signed char) * SECT[0].npoints);
	write(fd, SECT[0].vertex, sizeof(t_xy) * (SECT[0].npoints + 1));
	write(fd, SECT[0].texture, sizeof(int) * (SECT[0].npoints + 4));

	write(fd, SECT[1].neighbors, sizeof(signed char) * SECT[1].npoints);
	write(fd, SECT[1].vertex, sizeof(t_xy) * (SECT[1].npoints + 1));
	write(fd, SECT[1].texture, sizeof(int) * (SECT[1].npoints + 4));
}

void	default_player(t_main *m, int fd)
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
	write(fd, &USER, sizeof(t_player));
}

void	default_poster(t_main *m, int fd)
{
	MAP.num_poster = 1;
	write(fd, &MAP.num_poster, sizeof(unsigned));
	PIC = malloc(sizeof(t_poster) * MAP.num_poster);
	PIC[0].poz.x = 10;
	PIC[0].poz.y = 50;
	PIC[0].texture = 10;
	write(fd, PIC, sizeof(t_poster) * MAP.num_poster);
}

void	default_sprite(t_main *m, int fd)
{
	MAP.num_sprite = 1;
	write(fd, &MAP.num_sprite, sizeof(unsigned));
	OBJ = malloc(sizeof(t_sprite) * MAP.num_sprite);
	OBJ[0].poz.x = 40;
	OBJ[0].poz.y = 40;
	OBJ[0].texture = 11;
	write(fd, OBJ, sizeof(t_sprite) * MAP.num_sprite);
}
