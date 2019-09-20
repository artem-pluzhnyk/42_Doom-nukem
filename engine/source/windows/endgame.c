/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:00:57 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 15:27:29 by apluzhni         ###   ########.fr       */
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
	SDL_FreeSurface(sur);
	rect.y += 30;
	sur = TTF_RenderText_Solid(SDL.ttf_28,
	"Forever and ever, my brother, hail and farewell.", SDL.red);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	rect.y += 50;
	rect.x += 25;
	sur = TTF_RenderText_Solid(SDL.ttf_50,
	"Press Enter for respawn.", SDL.green);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	if (SDL.event.key.type == SDL_KEYDOWN
	&& SDL.event.key.keysym.sym == SDLK_RETURN)
	{
		m->state = 2;
		USER.health = 100;
		USER.armor = 125;
		USER.gun = 0;
		USER.sector = USER.spawn_sect;
		USER.where.x = USER.spawn.x;
		USER.where.y = USER.spawn.y;
		USER.where.z = USER.spawn.z;
	}
}
