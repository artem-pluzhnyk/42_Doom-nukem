/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:15:35 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 19:18:18 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	settings_window(t_main *m)
{
	SDL_Surface		*sur;
	SDL_Rect		rect;

	draw_background(m, SDL.texture[13]);
	map_choose(m);
	switch_music(m);
	switch_gravitation(m);
	switch_sky(m);
	switch_walls(m);
	switch_texture(m);
	tall_towers(m);
	rect.x = WIN_W / 24;
	rect.y = WIN_H / 1.1;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_50,
	"For change map you must restart game.", SDL.red);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
}

void	switch_music(t_main *m)
{
	SDL_Rect	rect;

	rect.h = SDL.texture[CFG.music + 18]->h / 3;
	rect.w = SDL.texture[CFG.music + 18]->w / 3;
	rect.x = rect.w / 10;
	rect.y = rect.h / 10;
	SDL_BlitScaled(SDL.texture[CFG.music + 18], NULL, SDL.sur, &rect);
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	{
		CFG.music = CFG.music ? 0 : 1;
		SDL_Delay(100);
	}
}

void	map_choose(t_main *m)
{
	SDL_Surface		*sur;
	SDL_Rect		rect;

	rect.x = WIN_W / 6;
	rect.y = WIN_H / 24;
	rect.w = 0;
	rect.h = 0;
	if (CFG.map)
		sur = TTF_RenderText_Solid(SDL.ttf_50, "Default map", SDL.yellow);
	else
		sur = TTF_RenderText_Solid(SDL.ttf_50, "Custom map", SDL.yellow);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	{
		CFG.map = CFG.map ? 0 : 1;
		SDL_Delay(100);
	}
}
