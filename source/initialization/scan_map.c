/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:32:44 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/03 15:23:28 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_map(t_main *m)
{
	int		fd;
	char	*map_file;

	map_file = "resource/maps/buffer.map";
	if ((fd = open(map_file, O_DIRECTORY) >= 0))
		ft_exit("☣ Error ☣");
	if ((fd = open(map_file, O_RDONLY)) < 0)
		create_map(m, map_file);
	else
		read_data(m, fd);
	close(fd);
}

void	read_data(t_main *m, int fd)
{
	int		i;

	read(fd, &m->num_v, sizeof(int));
	m->vert = malloc(sizeof(t_xy) * m->num_v);
	read(fd, m->vert, sizeof(t_xy) * m->num_v);
	read(fd, &m->num_s, sizeof(int));
	SECT = malloc(sizeof(t_sector) * m->num_s);
	read(fd, SECT, sizeof(t_sector) * m->num_s);
	i = -1;
	while (++i < (int)m->num_s)
	{
		SECT[i].neighbors = malloc(sizeof(signed char) * SECT[i].npoints);
		read(fd, SECT[i].neighbors, sizeof(signed char) * SECT[i].npoints);
		SECT[i].vertex = malloc(sizeof(t_xy) * (SECT[i].npoints + 1));
		read(fd, SECT[i].vertex, sizeof(t_xy) * (SECT[i].npoints + 1));
	}
	read(fd, &USER, sizeof(t_player));
}
