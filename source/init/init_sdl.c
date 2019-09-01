/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:15:34 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/01 17:18:23 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_sdl(t_main *m)
{
	int		request;

	if (SDL_Init(SDL_INIT_EVERYTHING))
		ft_exit("☢ SDL_Init error.");
	if (TTF_Init())
		ft_exit("☢ TTF_Init error.");
	if (!(Mix_Init(MIX_INIT_MP3)))
		ft_exit("☢ Mix_Init error.");
	request = SDL_GetDesktopDisplayMode(0, &SDL.display);
	if (!(SDL.win = SDL_CreateWindow("Doom 2077", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, WIN_FLG)))
		ft_exit("☢ SDL_CreateWindow error.");
	if (!(SDL.sur = SDL_GetWindowSurface(SDL.win)))
		ft_exit("☢ SDL_GetWindowSurface error.");
	SDL_CaptureMouse(SDL_TRUE);
}
