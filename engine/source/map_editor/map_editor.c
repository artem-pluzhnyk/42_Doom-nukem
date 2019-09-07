/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:18:15 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/14 21:04:16 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

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

	rect.w = 0;
	rect.h = 0;
	rect.y = 10;
	rect.x = 10;
	sur = TTF_RenderText_Solid(SDL.ttf_28, "Sector", (m->map_tab) ? SDL.white : SDL.yellow);
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
	sur = TTF_RenderText_Solid(SDL.ttf_28, "Objects", (m->map_tab) ? SDL.yellow : SDL.white);
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
