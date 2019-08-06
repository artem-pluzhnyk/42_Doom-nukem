/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:24:24 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/06 20:18:41 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_poster(t_main *m, int x, int y1, int y2)
{
	int			*pix;
	int			y;
	int			ty;
	int			tx;

	pix = (int*) SDL.sur->pixels;
	y1 = CLAMP(y1, 0, (int)WIN_H - 1);
	y2 = CLAMP(y2, 0, (int)WIN_H - 1);
	if (y2 == y1)
		pix[y1 * WIN_W + x] = ft_get_pixel(SDL.texture[REND.txtr_id], x, y1);
	else if (y2 > y1)
	{
		ty = -1;
		tx = x;
		y = y1 - 1;
		while (++y <= y2)
			pix[y * WIN_W + x] = ft_get_pixel(SDL.texture[REND.txtr_id], tx, ++ty);
	}
}
