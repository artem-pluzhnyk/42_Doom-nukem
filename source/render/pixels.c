/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:14:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/03 14:05:41 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_put_pixel(t_main *m, int x, int y, int pixel)
{
	int		*new_pixel;

	if (x < 0 || x > SDL.display.w || y < 0 || y > SDL.display.h - 2)
		return ;
	new_pixel = SDL.sur->pixels + y * SDL.sur->pitch
	+ x * SDL.sur->format->BytesPerPixel;
	*new_pixel = pixel;
}

int		ft_get_pixel(SDL_Surface *sur, int32_t x, int32_t y)
{
	int32_t		*pixel;

	pixel = 0;
	pixel = sur->pixels + y * sur->pitch + x * sur->format->BytesPerPixel;
	return (*pixel);
}

void	vline(t_main *m, int x, int y1,int y2)
{
	int		*pix;
	int		y;

	pix = (int*) SDL.sur->pixels;
	y1 = CLAMP(y1, 0, (int)WIN_H - 1);
	y2 = CLAMP(y2, 0, (int)WIN_H - 1);
	if (y2 == y1)
		pix[y1 * WIN_W + x] = ft_get_pixel(SDL.txtr[REND.texture_id], x, y1);
	else if (y2 > y1)
	{
		y = y1 - 1;
		REND.tex_y = 0;
		REND.tex_x = x;
		while (++y <= y2)
		{
			REND.tex_y++;
			// REND.tex_y = (y - y1) / (y2 - y1);
			pix[y * WIN_W + x] =
			ft_get_pixel(SDL.txtr[REND.texture_id], REND.tex_x, REND.tex_y);
		}
	}
}

void	draw_background(t_main *m)
{
	SDL.back_rect.x = 0;
	SDL.back_rect.y = 0;
	SDL.back_rect.h = WIN_H;
	SDL.back_rect.w = WIN_W;
	SDL_BlitScaled(SDL.txtr[0], NULL, SDL.sur, &SDL.back_rect);
}

t_xy	intersect(t_main *m)
{
	t_xy	s;

	s.x = VXS(VXS(IS.x1,IS.y1, IS.x2,IS.y2), (IS.x1)-(IS.x2),
	VXS(IS.x3,IS.y3, IS.x4,IS.y4), (IS.x3)-(IS.x4)) / VXS((IS.x1)-(IS.x2),
	(IS.y1)-(IS.y2), (IS.x3)-(IS.x4), (IS.y3)-(IS.y4));
	s.y = VXS(VXS(IS.x1,IS.y1, IS.x2,IS.y2), (IS.y1)-(IS.y2),
	VXS(IS.x3,IS.y3, IS.x4,IS.y4), (IS.y3)-(IS.y4)) / VXS((IS.x1)-(IS.x2),
	(IS.y1)-(IS.y2), (IS.x3)-(IS.x4), (IS.y3)-(IS.y4));
	return (s);
}
