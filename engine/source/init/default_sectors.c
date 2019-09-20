/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_sectors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:05:56 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 19:08:42 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	default_sectors(t_main *m)
{
	int		i;

	i = 0;
	MAP.num_s = 2;
	write(m->fd, &MAP.num_s, sizeof(int));
	SECT = malloc(sizeof(t_sector) * MAP.num_s);
	default_sector0(m);
	default_sector1(m);
	write(m->fd, SECT, sizeof(t_sector) * MAP.num_s);
	while (++i < (int)MAP.num_s)
	{
		write(m->fd, SECT[i].neighbors, sizeof(signed char) * SECT[i].npoints);
		write(m->fd, SECT[i].vertex, sizeof(t_xy) * (SECT[i].npoints + 1));
		write(m->fd, SECT[i].texture, sizeof(int) * (SECT[i].npoints + 4));
	}
}

void	default_sector0(t_main *m)
{
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
}

void	default_sector1(t_main *m)
{
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
}
