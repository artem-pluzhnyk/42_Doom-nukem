/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <akrivosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:35:37 by isavchen          #+#    #+#             */
/*   Updated: 2019/09/20 17:26:05 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_editor.h"

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
	m->head = NULL;
	m->num_v = 0;
}

void	loop(t_main *m)
{
	while (1)
	{
		SDL_FillRect(SDL.sur, NULL, 0x000000);
		map_editor(m);
				if(SDL_MOUSEBUTTONDOWN)
					coord(m);
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
	draw_points(m);
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

void	coord(t_main *m)
{
	int		x;
	int		y;
	t_vert	*new;

	if (SDL.event.button.button == SDL_BUTTON_LEFT)
	{
		x = SDL.event.button.x;
		y = SDL.event.button.y;
		new = (t_vert *)malloc(sizeof(t_vert));
		new->next = NULL;
		new->xy.x = x;
		new->xy.y = y;
		if (m->head == NULL)
		{
			m->head = new;
			m->last = m->head;
		}
		else
		{
			m->last->next = new;
			m->last = new;
		}
		SDL_UpdateWindowSurface(SDL.win);
		SDL_Delay(100);
	}
}

void	draw_points(t_main *m)
{
	t_vert *walk;

	walk = m->head;
	while (walk)
	{
		ft_put_pixel(m, walk->xy.x, walk->xy.y, 0x00CA00);
		walk = walk->next;
		m->num_v++;
	}
}
