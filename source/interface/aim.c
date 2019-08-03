/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:49:55 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/27 14:53:44 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		draw_aim(t_main *m)
{
	SDL.rect[0].x = 0;
	SDL.rect[0].y = 0;
	SDL.rect[0].h = WIN_H;
	SDL.rect[0].w = WIN_W;
	SDL_SetColorKey(SDL.txtr[4], SDL_TRUE, SDL_MapRGB(SDL.txtr[4]->format, 0, 0, 0));
	SDL_BlitScaled(SDL.txtr[4], NULL, SDL.sur, &SDL.rect[0]);
	return (0);
}

void	draw_aim_distance(t_main *m)
{
	SDL_Surface		*text_sur;
	int				h;
	int				w;
	char			*str;
	char			*str1;
	char			*str2;

	SDL.text_rect.w = 0;
	SDL.text_rect.h = 0;
	str = malloc(sizeof(char) * (ft_nbrlen(REND.z) + 4));
	str1 = ft_strjoin(ft_itoa(REND.z / 10), ",");
	str2 = ft_strjoin(ft_itoa(REND.z % 10), " m.");
	str = ft_strjoin(str1, str2);
	TTF_SizeText(SDL.ttf2, str, &w, &h);
	SDL.text_rect.y = WIN_H / 2 + WIN_H / 4;
	SDL.text_rect.x = WIN_W / 2 - w / 3;
	text_sur = TTF_RenderText_Solid(SDL.ttf2, str, SDL.color);
	SDL_BlitSurface(text_sur, NULL, SDL.sur, &SDL.text_rect);
	SDL_FreeSurface(text_sur);
}
