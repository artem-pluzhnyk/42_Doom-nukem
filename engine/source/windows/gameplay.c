/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:21:17 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/09 18:59:18 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	gameplay(t_main *m)
{
	Mix_PauseMusic();
	render_all(m);
	draw_hud(m);
	healing_player(m);
	radiation(m);
	if (USER.health <= 0)
		m->state = 5;
	// draw_poster(m); // Posters
	// draw_sprite(m); // Sprites
	if (HUD.hud)
		draw_gun(m, SDL.texture[15]);
	else
	{
		draw_aim(m, SDL.texture[4]);
		aim_distance(m);
	}
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}
