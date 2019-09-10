/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:00:57 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/10 19:31:21 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <doom.h>

void	endgame(t_main *m)
{
	SDL_Surface		*sur;
	SDL_Rect		rect;

	rect.x = WIN_W / 5;
	rect.y = WIN_H / 22;
	rect.w = 0;
	rect.h = 0;
	draw_background(m, SDL.texture[16]);
	sur = TTF_RenderText_Solid(SDL.ttf_28,
	"Atque in pepetuum, frater, ave atque vale.", SDL.red);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	rect.y += 30;
	sur = TTF_RenderText_Solid(SDL.ttf_28,
	"Forever and ever, my brother, hail and farewell.", SDL.red);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);

	if (SDL.event.key.type == SDL_KEYDOWN
	&& SDL.event.key.keysym.sym == SDLK_RETURN)
	{
		m->state = 1;
		USER.health = 100;
		USER.armor = 125;
		USER.sector = 0;
		USER.where.x = 5;
		USER.where.y = 5;
		USER.where.z = MAP.sectors[USER.sector].floor + EYE_H;
	}
}
// save defoult position
// respawn text
// map choose
