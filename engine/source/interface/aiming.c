/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aiming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:22:02 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/18 19:06:11 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	aim_distance(t_main *m)
{
	SDL_Surface		*sur;
	SDL_Rect		rect;
	int				h;
	int				w;
	char			*str;

	str = malloc(sizeof(char) * (ft_nbrlen(REND.z) + 4));
	str = ft_strjoin(ft_strjoin(ft_itoa(REND.z / 10), ","),
	ft_strjoin(ft_itoa(REND.z % 10), " m."));
	TTF_SizeText(SDL.ttf_28, str, &w, &h);
	rect.x = WIN_W / 2 - w / 3;
	rect.y = WIN_H / 2 + WIN_H / 4;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_28, str, SDL.white);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
}

void	draw_aim(t_main *m)
{
	SDL_Rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.h = WIN_H;
	rect.w = WIN_W;
	SDL_SetColorKey(SDL.texture[4], SDL_TRUE, SDL_MapRGB(SDL.texture[4]->format, 255, 255, 255));
	SDL_BlitScaled(SDL.texture[4], NULL, SDL.sur, &rect);
}
