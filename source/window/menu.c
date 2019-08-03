/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:39:02 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/31 18:48:13 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	menu(t_main *m)
{
	SDL_ShowCursor(SDL_ENABLE);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	draw_background(m);
	draw_button(m);
	button_text(m, SDL.rect[0].x, SDL.rect[0].y, SDL.rect[0].w, SDL.rect[0].h);
	button_click(m);
}

void	draw_button(t_main *m)
{
	SDL.rect[0].h = WIN_H / 10;
	SDL.rect[0].w = WIN_W / 5;
	SDL.rect[0].x = WIN_W / 2 - SDL.rect[0].w / 2;
	SDL.rect[0].y = WIN_H / 2 - SDL.rect[0].h / 2 + SDL.rect[0].h;
	SDL_BlitScaled(SDL.txtr[1], NULL, SDL.sur, &SDL.rect[0]);
	SDL.rect[1].h = WIN_H / 10;
	SDL.rect[1].w = SDL.rect[1].h;
	SDL.rect[1].x = WIN_W - SDL.rect[1].w;
	SDL.rect[1].y = 0;
	SDL_BlitScaled(SDL.txtr[2], NULL, SDL.sur, &SDL.rect[1]);
	SDL.rect[2].h = WIN_H / 11;
	SDL.rect[2].w = SDL.rect[2].h;
	SDL.rect[2].x = WIN_W - SDL.rect[2].w - SDL.rect[2].w;
	SDL.rect[2].y = 0;
	SDL_BlitScaled(SDL.txtr[3], NULL, SDL.sur, &SDL.rect[2]);
}

void	button_text(t_main *m, int x, int y, int w, int h)
{
	SDL_Surface		*sur;

	SDL.text_rect.x = x + w / 3;
	SDL.text_rect.y = y + h / 3;
	SDL.text_rect.w = 0;
	SDL.text_rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf,"Play", SDL.color);
	SDL_BlitSurface(sur, NULL, SDL.sur, &SDL.text_rect);
	SDL_FreeSurface(sur);
}

void	button_click(t_main *m)
{
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= SDL.rect[0].x
	&& SDL.event.button.x <= (SDL.rect[0].x + SDL.rect[0].w)
	&& SDL.event.button.y >= SDL.rect[0].y
	&& SDL.event.button.y <= (SDL.rect[0].x + SDL.rect[0].h))
		m->state = 2;
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= SDL.rect[1].x
	&& SDL.event.button.x <= (SDL.rect[1].x + SDL.rect[1].w)
	&& SDL.event.button.y >= SDL.rect[1].y
	&& SDL.event.button.y <= (SDL.rect[1].x + SDL.rect[1].h))
		m->state = 3;
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= SDL.rect[2].x
	&& SDL.event.button.x <= (SDL.rect[2].x + SDL.rect[2].w)
	&& SDL.event.button.y >= SDL.rect[2].y
	&& SDL.event.button.y <= (SDL.rect[2].x + SDL.rect[2].h))
		m->state = 4;
}
