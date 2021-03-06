/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:51:39 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 19:25:46 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	menu(t_main *m)
{
	if (!(Mix_PlayingMusic()) && CFG.music)
		Mix_PlayMusic(SDL.sound, -1);
	SDL_ShowCursor(SDL_ENABLE);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	draw_background(m, SDL.texture[0]);
	play_btn(m);
	setting_btn(m);
}

void	play_btn(t_main *m)
{
	SDL_Rect	rect;
	SDL_Surface	*sur;

	rect.h = WIN_H / 10;
	rect.w = WIN_W / 5;
	rect.x = WIN_W / 2 - rect.w / 2;
	rect.y = WIN_H / 2 - rect.h / 2 + rect.h;
	SDL_BlitScaled(SDL.texture[1], NULL, SDL.sur, &rect);
	rect.x = rect.x + rect.w / 3;
	rect.y = rect.y + rect.h / 3;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_50, "Play", SDL.white);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	start_game(m, rect);
}

void	setting_btn(t_main *m)
{
	SDL_Rect	rect;

	rect.h = WIN_H / 10;
	rect.w = rect.h;
	rect.x = WIN_W - rect.w;
	rect.y = 0;
	SDL_BlitScaled(SDL.texture[2], NULL, SDL.sur, &rect);
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	{
		m->state = 3;
		Mix_HaltMusic();
		SDL_Delay(100);
	}
}

void	start_game(t_main *m, SDL_Rect rect)
{
	if ((SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	|| (SDL.event.key.type == SDL_KEYDOWN
	&& SDL.event.key.keysym.sym == SDLK_RETURN))
	{
		m->state = 2;
		Mix_HaltMusic();
		SDL_Delay(100);
	}
}
