/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:38:43 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/01 20:38:21 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	loading_screen(t_main *m)
{
	draw_background(m);
	write_loading_text(m);
}

void	write_loading_text(t_main *m)
{
	SDL_Surface		*text_sur;

	SDL.text_rect.x = WIN_W / 3;
	SDL.text_rect.y = WIN_H - WIN_H / 8;
	SDL.text_rect.w = 0;
	SDL.text_rect.h = 0;
	text_sur = TTF_RenderText_Solid(SDL.ttf,"Doom 2077 is loaded", SDL.color);
	SDL_BlitSurface(text_sur, NULL, SDL.sur, &SDL.text_rect);
	SDL.text_rect.y += 30;
	text_sur = TTF_RenderText_Solid(SDL.ttf,"Press Enter to continue", SDL.color);
	SDL_BlitSurface(text_sur, NULL, SDL.sur, &SDL.text_rect);
	SDL_FreeSurface(text_sur);
}
