/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:22:02 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/14 14:44:16 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	main_aim(t_main *m)
{
	SDL_Rect	rect;

	rect.h = SDL.texture[20]->w;
	rect.w = SDL.texture[20]->h;
	rect.x = WIN_W / 2 - SDL.texture[20]->w / 2;
	rect.y = WIN_H / 2 - SDL.texture[20]->h / 2;
	SDL_SetColorKey(SDL.texture[20], SDL_TRUE, SDL_MapRGB(SDL.texture[20]->format, 255, 255, 255));
	SDL_BlitScaled(SDL.texture[20], NULL, SDL.sur, &rect);
}
