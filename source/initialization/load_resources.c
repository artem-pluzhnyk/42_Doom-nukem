/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:25:20 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/03 15:37:00 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_textures(t_main *m)
{
	if (!(SDL.txtr[0] = SDL_LoadBMP("resources/textures/menu.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[1] = SDL_LoadBMP("resources/textures/btn.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[2] = SDL_LoadBMP("resources/textures/setting.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[3] = SDL_LoadBMP("resources/textures/map.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[4] = SDL_LoadBMP("resources/textures/aim.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[5] = SDL_LoadBMP("resources/textures/hud.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[6] = SDL_LoadBMP("resources/textures/sky.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[7] = SDL_LoadBMP("resources/textures/texture1.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[8] = SDL_LoadBMP("resources/textures/texture2.bmp")))
		ft_exit("☣ Error ☣");
	if (!(SDL.txtr[9] = SDL_LoadBMP("resources/textures/grass.bmp")))
		ft_exit("☣ Error ☣");
}

void	load_font(t_main *m)
{
	if (!(SDL.ttf = TTF_OpenFont("resources/font/SAMBD.ttf", 50)))
		ft_exit("☣ Error ☣");
	TTF_SetFontStyle(SDL.ttf, TTF_STYLE_NORMAL);
	TTF_SetFontOutline(SDL.ttf, 1);
	TTF_SetFontKerning(SDL.ttf, 1);
	TTF_SetFontHinting(SDL.ttf, TTF_HINTING_NORMAL);
	if (!(SDL.ttf2 = TTF_OpenFont("resources/font/SAMBD.ttf", 28)))
		ft_exit("☣ Error ☣");
	TTF_SetFontStyle(SDL.ttf2, TTF_STYLE_NORMAL);
}
