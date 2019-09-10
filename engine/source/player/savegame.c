/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savegame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:11:49 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/10 13:15:57 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "doom.h"

void	save_game(t_main *m)
{
	system("rm -f ../resources/maps/default.map");
	m->fd = open("../resources/maps/default.map", O_CREAT | O_RDWR);
	write(m->fd, &MAP.num_v, sizeof(int));
	write(m->fd, MAP.vert, sizeof(t_xy) * MAP.num_v);
	write(m->fd, &MAP.num_s, sizeof(int));
	write(m->fd, SECT, sizeof(t_sector) * MAP.num_s);
	write(m->fd, SECT[0].neighbors, sizeof(signed char) * SECT[0].npoints);
	write(m->fd, SECT[0].vertex, sizeof(t_xy) * (SECT[0].npoints + 1));
	write(m->fd, SECT[0].texture, sizeof(int) * (SECT[0].npoints + 4));
	write(m->fd, SECT[1].neighbors, sizeof(signed char) * SECT[1].npoints);
	write(m->fd, SECT[1].vertex, sizeof(t_xy) * (SECT[1].npoints + 1));
	write(m->fd, SECT[1].texture, sizeof(int) * (SECT[1].npoints + 4));
	write(m->fd, &USER, sizeof(t_player));
	write(m->fd, &MAP.num_poster, sizeof(unsigned));
	write(m->fd, PIC, sizeof(t_poster) * MAP.num_poster);
	write(m->fd, &MAP.num_sprite, sizeof(unsigned));
	write(m->fd, OBJ, sizeof(t_sprite) * MAP.num_sprite);
}
