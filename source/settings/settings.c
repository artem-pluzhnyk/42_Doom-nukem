/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:55:29 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/02 18:33:11 by apluzhni         ###   ########.fr       */
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
		default_setings(m);
	else
		read(fd, &CFG, sizeof(t_cfg));
	close(fd);
}

void	default_setings(t_main *m)
{
	int		fd;

	fd = open("setting.cfg", O_CREAT | O_RDWR);
	CFG.win_width = 1500;
	CFG.win_height = 1000;
	write(fd, &CFG, sizeof(t_cfg));
	close(fd);
}
