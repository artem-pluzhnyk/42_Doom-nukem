/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:25:20 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/03 18:41:06 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	initialization_sdl(t_main *m)
{
	int		request;

	if (SDL_Init(SDL_INIT_EVERYTHING))
		ft_exit("☢ SDL error.");
	if (TTF_Init() < 0)
		ft_exit("☢ SDL error.");
	request = SDL_GetDesktopDisplayMode(0, &SDL.display);
	if (!(SDL.win = SDL_CreateWindow("Doom 2077", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, WIN_FLG)))
		ft_exit("☢ SDL error.");
	if (!(SDL.sur = SDL_GetWindowSurface(SDL.win)))
		ft_exit("☢ SDL error.");
	// SDL_SetWindowGrab(SDL.win, SDL_TRUE);
	// SDL_CaptureMouse(SDL_TRUE);
}

void	initialization_data(t_main *m)
{
	m->state = 0;
	m->dat_load = 1;
	MOV.wsad[0] = 0;
	MOV.wsad[1] = 0;
	MOV.wsad[2] = 0;
	MOV.wsad[3] = 0;
	MOV.ground = 0;
	MOV.falling = 1;
	MOV.moving = 0;
	MOV.ducking = 0;
	MOV.yaw = 0;
	SDL.color.r = 255;
	SDL.color.g = 255;
	SDL.color.b = 255;
}
