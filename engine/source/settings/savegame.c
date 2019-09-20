/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savegame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:11:49 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 18:25:59 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	save_game(t_main *m)
{
	int		i;

	i = -1;
	if (m->loaded_map)
		m->fd = open("../resources/maps/default.map", O_RDWR);
	else
		m->fd = open("../resources/maps/custom.map", O_RDWR);
	write(m->fd, &MAP.num_v, sizeof(int));
	write(m->fd, MAP.vert, sizeof(t_xy) * MAP.num_v);
	write(m->fd, &MAP.num_s, sizeof(int));
	write(m->fd, SECT, sizeof(t_sector) * MAP.num_s);
	while (++i < (int)MAP.num_s)
	{
		write(m->fd, SECT[i].neighbors, sizeof(signed char) * SECT[i].npoints);
		write(m->fd, SECT[i].vertex, sizeof(t_xy) * (SECT[i].npoints + 1));
		write(m->fd, SECT[i].texture, sizeof(int) * (SECT[i].npoints + 4));
	}
	write(m->fd, &USER, sizeof(t_player));
}
