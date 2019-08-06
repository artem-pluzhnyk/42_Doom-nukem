/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:18:15 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/06 15:20:37 by apluzhni         ###   ########.fr       */
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

	x = 300;
	while (++x < (int)WIN_W - 1)
	{
		y = 0;
		while (++y < (int)WIN_H - 1)
		{
			if (!(y % 10) || !(x % 10))
				ft_put_pixel(m, x, y, WHITE);
			if (!(y % 100) || !(x % 100))
			{
				ft_put_pixel(m, x + 1, y, WHITE);
				ft_put_pixel(m, x - 1, y, WHITE);
				ft_put_pixel(m, x, y + 1, WHITE);
				ft_put_pixel(m, x, y - 1, WHITE);
			}
		}
	}
}

void	map_tabs(t_main *m)
{
	SDL_Surface		*sur;
	SDL_Rect		rect;
	char			*str;

	rect.w = 0;
	rect.h = 0;
	rect.y = 10;
	rect.x = 10;
	str = malloc(sizeof(char*));
	str = "Sector";
	sur = TTF_RenderText_Solid(SDL.ttf_28, str, SDL.white);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
}
