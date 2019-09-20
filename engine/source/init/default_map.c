/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:23:43 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 19:06:48 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	create_map(t_main *m, char *file)
{
	m->fd = open(file, O_CREAT | O_RDWR);
	default_vertex(m);
	default_sectors(m);
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
