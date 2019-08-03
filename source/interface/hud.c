/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:27:03 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/17 16:42:49 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_hud(t_main *m)
{
	SDL.rect[0].x = 0;
	SDL.rect[0].y = 0;
	SDL.rect[0].h = WIN_H;
	SDL.rect[0].w = WIN_W;
	SDL_SetColorKey(SDL.txtr[5], SDL_TRUE, SDL_MapRGB(SDL.txtr[4]->format, 0, 0, 0));
	SDL_BlitScaled(SDL.txtr[5], NULL, SDL.sur, &SDL.rect[0]);
}
