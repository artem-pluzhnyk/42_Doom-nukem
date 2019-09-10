/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:40:31 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/10 14:29:50 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	loading_screen(t_main *m)
{
	SDL_Rect	rect;

	rect.x = WIN_W / 4;
	rect.y = 0;
	rect.h = WIN_H / 1.15;
	rect.w = WIN_W / 2;
	SDL_BlitScaled(SDL.texture[17], NULL, SDL.sur, &rect);
	loading_text(m);
}

void	loading_text(t_main *m)
{
	SDL_Surface		*sur;
	SDL_Rect		rect;

	rect.x = WIN_W / 3;
	rect.y = WIN_H - WIN_H / 8;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_50,"Doom 2077 is loaded", SDL.blue);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	rect.y += 30;
	sur = TTF_RenderText_Solid(SDL.ttf_50,"Press Enter to continue", SDL.blue);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
}
