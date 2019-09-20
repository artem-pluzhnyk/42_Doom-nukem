/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:34:07 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 19:34:19 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_sky(t_main *m)
{
	SDL_Rect	win;

	win.x = 0;
	win.y = 0;
	win.h = WIN_H;
	win.w = WIN_W;
	SDL_BlitScaled(SDL.texture[6], &SDL.view, SDL.sur, &win);
}

void	move_sky(t_main *m, int x, int y)
{
	SDL.view.x += x * 25;
	SDL.view.y += y / 2;
	SDL.view.x = (SDL.view.x < 0) ? SDL.texture[6]->w - SDL.view.w : SDL.view.x;
	SDL.view.y = (SDL.view.y < 0) ? 0 : SDL.view.y;
	SDL.view.x = (SDL.view.x > SDL.texture[6]->w - SDL.view.w) ? 0 : SDL.view.x;
	SDL.view.y = (SDL.view.y > SDL.texture[6]->h - SDL.view.h)
		? SDL.texture[6]->h - SDL.view.h : SDL.view.y;
}
