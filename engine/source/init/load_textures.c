/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:10:00 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/10 12:01:30 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_textures(t_main *m)
{
	if (!(SDL.texture[0] = SDL_LoadBMP("../resources/textures/menu.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[1] = SDL_LoadBMP("../resources/textures/btn.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[2] = SDL_LoadBMP("../resources/textures/setting.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[3] = SDL_LoadBMP("../resources/textures/map.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[4] = SDL_LoadBMP("../resources/textures/aim.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[5] = SDL_LoadBMP("../resources/textures/hud.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[6] = SDL_LoadBMP("../resources/textures/sky.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[7] = SDL_LoadBMP("../resources/textures/texture1.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[8] = SDL_LoadBMP("../resources/textures/texture2.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[9] = SDL_LoadBMP("../resources/textures/grass.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[10] = SDL_LoadBMP("../resources/textures/poster1.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[11] = SDL_LoadBMP("../resources/textures/atm.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[12] = SDL_LoadBMP("../resources/textures/floor.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[13] = SDL_LoadBMP("../resources/textures/wall.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[14] = SDL_LoadBMP("../resources/textures/ceiling.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[15] = SDL_LoadBMP("../resources/textures/shotgun.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[16] = SDL_LoadBMP("../resources/textures/rip.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.texture[17] = SDL_LoadBMP("../resources/textures/comics.bmp")))
		ft_exit("☣ Error ☣");

}
