/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:22:04 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/03 13:01:55 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_map(t_main *m)
{
	int		fd;
	char	*file;

	file = "resources/maps/level0.map";
	if ((fd = open(file, O_DIRECTORY) >= 0))
		ft_exit("☣ Error ☣");
	if ((fd = open(file, O_RDONLY)) < 0)
		create_map(m, file);
	else
		read_map(m, fd);
	close(fd);
}

void	read_map(t_main *m, int fd)
{
	unsigned	i;

	read(fd, &MAP.num_v, sizeof(int));
	MAP.vert = malloc(sizeof(t_xy) * MAP.num_v);
	read(fd, MAP.vert, sizeof(t_xy) * MAP.num_v);
	read(fd, &MAP.num_s, sizeof(int));
	SECT = malloc(sizeof(t_sector) * MAP.num_s);
	read(fd, SECT, sizeof(t_sector) * MAP.num_s);
	i = -1;
	while (++i < MAP.num_s)
	{
		SECT[i].neighbors = malloc(sizeof(signed char) * SECT[i].npoints);
		read(fd, SECT[i].neighbors, sizeof(signed char) * SECT[i].npoints);
		SECT[i].vertex = malloc(sizeof(t_xy) * (SECT[i].npoints + 1));
		read(fd, SECT[i].vertex, sizeof(t_xy) * (SECT[i].npoints + 1));
		SECT[i].texture = malloc(sizeof(int) * (SECT[i].npoints + 4));
		read(fd, SECT[i].texture, sizeof(int) * (SECT[i].npoints + 4));
	}
	read(fd, &USER, sizeof(t_player));

	read(fd, &MAP.num_poster, sizeof(unsigned));
	PIC = malloc(sizeof(t_poster) * MAP.num_poster);
	read(fd, PIC, sizeof(t_poster));

	read(fd, &MAP.num_sprite, sizeof(unsigned));
	OBJ = malloc(sizeof(t_sprite) * MAP.num_sprite);
	read(fd, OBJ, sizeof(t_sprite));
}
