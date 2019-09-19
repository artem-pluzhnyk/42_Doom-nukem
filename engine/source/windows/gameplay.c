/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:21:17 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/19 14:43:11 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	gameplay(t_main *m)
{
	Mix_PauseMusic();
	if (CFG.sky || !(CFG.walls))
		draw_background(m, SDL.texture[6]); // draw_sky(m);
	render_all(m);
	draw_hud(m);
	healing_player(m);
	radiation(m);
	if (SECT[USER.sector].gun)
		USER.gun = 1;
	if (USER.health <= 0)
		m->state = 5;
	if (HUD.hud)
	{
		main_aim(m);
		if (!(SDL.gun.x) && USER.gun)
			draw_gun(m);
	}
	else
	{
		draw_aim(m);
		aim_distance(m);
	}
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

// void	draw_sky(t_main *m) /////////////////////////////////////////////////////////////////
