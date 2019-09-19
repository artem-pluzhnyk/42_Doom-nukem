/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:55:29 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/19 14:43:22 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_settings(t_main *m)
{
	int		fd;

	fd = 0;
	if ((fd = open("../resources/setting.cfg", O_DIRECTORY) >= 0))
		ft_exit("☣ Error ☣");
	if ((fd = open("../resources/setting.cfg", O_RDONLY)) < 0)
		default_setings(m);
	else
		read(fd, &CFG, sizeof(t_cfg));
	close(fd);
	m->loaded_map = CFG.map;
}

void	default_setings(t_main *m)
{
	int		fd;

	fd = open("../resources/setting.cfg", O_CREAT | O_RDWR);
	CFG.win_width = 1500;
	CFG.win_height = 1000;
	CFG.music = 1;
	CFG.map = 1;
	CFG.fly = 1;
	CFG.sky = 0;
	CFG.walls = 1;
	write(fd, &CFG, sizeof(t_cfg));
	close(fd);
}

void	save_settings(t_main *m)
{
	int		fd;

	fd = open("../resources/setting.cfg", O_RDWR);
	write(fd, &CFG, sizeof(t_cfg));
	close(fd);
}
