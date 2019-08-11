/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:22:00 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/11 10:32:59 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_hud(t_main *m, SDL_Surface *sur)
{
	SDL_Rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.h = WIN_H;
	rect.w = WIN_W;
	SDL_SetColorKey(sur, SDL_TRUE, SDL_MapRGB(sur->format, 0, 0, 0));
	SDL_BlitScaled(sur, NULL, SDL.sur, &rect);
}
