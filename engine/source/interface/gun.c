/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:22:00 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/14 17:50:08 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_gun(t_main *m)
{
	SDL_Rect	rect;

	SDL.gun.y = 0;
	SDL.gun.h = 150;
	SDL.gun.w = 149;
	rect.h = SDL.gun.h * 3;
	rect.w = SDL.gun.w * 3;
	rect.x = WIN_W / 2;
	rect.y = WIN_H - rect.h;
	SDL_BlitScaled(SDL.texture[15], &SDL.gun, SDL.sur, &rect);
}

void	gun_animation(t_main *m)
{
	while (SDL.gun.x != 600)
	{
		SDL.gun.x += 150;
		SDL_FillRect(SDL.sur, NULL, 0x000000);
		select_window(m);
		events(m);
		while (SDL_PollEvent(&SDL.event))
			events_sdl(m);
		draw_gun(m);
		SDL_UpdateWindowSurface(SDL.win);
		SDL_Delay(50);
	}
	SDL.gun.x = 0;
}
