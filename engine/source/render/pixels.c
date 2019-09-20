/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:14:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 19:34:12 by apluzhni         ###   ########.fr       */
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

void	vline(t_main *m, int x, int y1, int y2)
{
	int			*pix;
	int			y;
	unsigned	txty;
	int			color;

	pix = (int*)SDL.sur->pixels;
	y1 = CLAMP(y1, 0, (int)WIN_H - 1);
	y2 = CLAMP(y2, 0, (int)WIN_H - 1);
	pix += y1 * WIN_W + x;
	y = y1 - 1;
	while (++y <= y2)
	{
		txty = scaler_next(&SCAL);
		color = color_transoform(ft_get_pixel(SDL.texture[REND.txtr_id],
		REND.txtx % SDL.texture[REND.txtr_id]->w, txty
			% SDL.texture[REND.txtr_id]->h),
		percentage(255, 0, REND.z));
		*pix = (!(CFG.walls) && color <= 0x010101) ? *pix : color;
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
