/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:22:47 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/27 13:29:20 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_settings(t_main *m)
{
	int		fd;

	fd = 0;
	if ((fd = open("setting.cfg", O_DIRECTORY) >= 0))
		ft_exit("☣ Error ☣");
	if ((fd = open("setting.cfg", O_RDONLY)) < 0)
		create_setings_file(m);
	fd = open("setting.cfg", O_RDONLY);
	read(fd, &CFG, sizeof(t_cfg));
	close(fd);
}

void	create_setings_file(t_main *m)
{
	int		fd;

	fd = open("setting.cfg", O_CREAT | O_RDWR);
	CFG.aim_enable = 0;
	CFG.aim_size = 50;
	CFG.window_width = 1500;
	CFG.window_height = 1000;
	write(fd, &CFG, sizeof(t_cfg));
	close(fd);
}
