/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:14:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/14 19:52:55 by apluzhni         ###   ########.fr       */
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

void	vline(t_main *m, int x, int y1, int y2, unsigned txtx)
{
	int			*pix;
	int			y;
	unsigned	txty;

	pix = (int*) SDL.sur->pixels;
	y1 = CLAMP(y1, 0, (int)WIN_H - 1);
	y2 = CLAMP(y2, 0, (int)WIN_H - 1);
	pix += y1 * WIN_W + x;
	y = y1 - 1;
	while (++y <= y2)
	{
		txty = scaler_next(&SCAL);
		*pix = color_transoform(ft_get_pixel(SDL.texture[REND.txtr_id],
		txtx % SDL.texture[REND.txtr_id]->w, txty % SDL.texture[REND.txtr_id]->h),
		percentage(255, 0, REND.z));
		pix += WIN_W;
	}
}

void	draw_background(t_main *m, SDL_Surface *sur)
{
	SDL_Rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.h = WIN_H;
	rect.w = WIN_W;
	SDL_BlitScaled(sur, NULL, SDL.sur, &rect);
}

float	percentage(int start, int end, int curr)
{
	float place;
	float dist;

	place = curr - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int		color_transoform(int color, float percent)
{
	int		rgb[3];

	rgb[0] = ((color >> 16) & 0xFF) * percent;
	rgb[1] = ((color >> 8) & 0xFF) * percent;
	rgb[2] = ((color) & 0xFF) * percent;
	color = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	return (color);
}
