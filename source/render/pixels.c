/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:14:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/04 14:32:33 by apluzhni         ###   ########.fr       */
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
		*pix = ft_get_pixel(SDL.txtr[REND.txtr_id], txtx % 1024, txty % 1024);
		pix += WIN_W;
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
