/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:24:24 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/07 15:57:28 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_poster(t_main *m, int x, int y1, int y2, unsigned txtx)
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
		*pix = ft_get_pixel(SDL.texture[REND.txtr_id],
		txtx % SDL.texture[REND.txtr_id]->w,
		txty % SDL.texture[REND.txtr_id]->h);
		pix += WIN_W;
	}
}
