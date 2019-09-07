/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:22:00 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/07 14:48:55 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_gun(t_main *m, SDL_Surface *sur)
{
	SDL_Rect	rect;
	SDL_Rect	t_rect;

	t_rect.x = 0;
	t_rect.y = 0;
	t_rect.h = 150;
	t_rect.w = 149;
	rect.h = t_rect.h * 3;
	rect.w = t_rect.w * 3;
	rect.x = WIN_W / 2 - rect.w / 2;
	rect.y = WIN_H - rect.h;
	SDL_BlitScaled(sur, &t_rect, SDL.sur, &rect);
}
