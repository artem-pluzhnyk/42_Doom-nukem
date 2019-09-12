/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <akrivosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:43:39 by akrivosh          #+#    #+#             */
/*   Updated: 2019/09/07 18:15:32 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map-editor.h"

int		main(void)
{
	t_main	m;

	init_sdl(&m);
	loop(&m);
	return (0);
}

void	init_sdl(t_main *m)
{
	int		request;

	if (SDL_Init(SDL_INIT_EVERYTHING))
		exit(EXIT_FAILURE);
	if (TTF_Init())
		exit(EXIT_FAILURE);
	request = SDL_GetDesktopDisplayMode(0, &SDL.display);
	if (!(SDL.win = SDL_CreateWindow("Doom 2077 [map editor mode]",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, WIN_FLG)))
		exit(EXIT_FAILURE);
	if (!(SDL.sur = SDL_GetWindowSurface(SDL.win)))
		exit(EXIT_FAILURE);
	if (!(SDL.ttf = TTF_OpenFont("../resources/font/SAMBD.ttf", 28)))
		exit(EXIT_FAILURE);
	SDL_CaptureMouse(SDL_TRUE);
	SDL.white.r = 255;
	SDL.white.g = 255;
	SDL.white.b = 255;
	SDL.yellow.r = 255;
	SDL.yellow.g = 255;
	SDL.yellow.b = 0;
	m->i = 0;
}

void	get_mouse(t_main *m)
{
	SDL_Rect	rect;
	t_vert		v;
	int		x;
	int		y;

	rect.w = WIN_W; // WIN_W
	rect.h = WIN_H; // WIN_H
	rect.y = 0; // 0
	rect.x = 250; // 250
	SDL_GetMouseState(&x, &y);
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= rect.w
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= rect.h)
	{
		v.coord[m->i].x = SDL.event.button.x;
		v.coord[m->i].y = SDL.event.button.y;
		if (SDL.event.button.x != v.coord[m->i].x || SDL.event.button.y != v.coord[m->i].y)
			m->i += 1;

		printf("x1 = %d\ny1 = %d\ni = %d\n", v.coord[m->i].x, v.coord[m->i].y, m->i);
	}
}

void	loop(t_main *m)
{
	while (1)
	{
		SDL_FillRect(SDL.sur, NULL, 0x000000);
		map_editor(m);
		get_mouse(m);
		while (SDL_PollEvent(&SDL.event))
			if ((SDL.event.type == SDL_QUIT) ||
			(SDL.event.key.type == SDL_KEYDOWN
			&& SDL.event.key.keysym.sym == SDLK_ESCAPE))
				exit(EXIT_SUCCESS);
		SDL_UpdateWindowSurface(SDL.win);
	}
}

void	map_editor(t_main *m)
{
	draw_grid(m);
	map_tabs(m);
}

void	draw_grid(t_main *m)
{
	int		x;
	int		y;

	x = 250;
	while (++x < (int)WIN_W - 1)
	{
		y = 0;
		while (++y < (int)WIN_H - 1)
		{
			if (!(y % 10) || !(x % 10))
				ft_put_pixel(m, x, y, GRAY);
			if (!(y % 100) || !(x % 100))
			{
				ft_put_pixel(m, x + 1, y, GRAY);
				ft_put_pixel(m, x - 1, y, GRAY);
				ft_put_pixel(m, x, y + 1, GRAY);
				ft_put_pixel(m, x, y - 1, GRAY);
			}
		}
	}
}

void	map_tabs(t_main *m)
{
	SDL_Surface		*sur;
	SDL_Rect		rect;

	rect.w = 0; // WIN_W
	rect.h = 0; // WIN_H
	rect.y = 10; // 0
	rect.x = 10; // 250
	sur = TTF_RenderText_Solid(SDL.ttf, "Sector", (m->map_tab) ? SDL.white : SDL.yellow);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
		m->map_tab = 0;
	rect.x += 110;
	sur = TTF_RenderText_Solid(SDL.ttf, "Objects", (m->map_tab) ? SDL.yellow : SDL.white);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
		m->map_tab = 1;
}

void	ft_put_pixel(t_main *m, int x, int y, int pixel)
{
	int		*new_pixel;

	if (x < 0 || x > SDL.display.w || y < 0 || y > SDL.display.h - 2)
		return ;
	new_pixel = SDL.sur->pixels + y * SDL.sur->pitch
	+ x * SDL.sur->format->BytesPerPixel;
	*new_pixel = pixel;
}
