/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:21:17 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/14 14:45:48 by apluzhni         ###   ########.fr       */
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
	if (HUD.hud)
	{
		main_aim(m);
		draw_gun(m, SDL.texture[15]);
	}
	else
	{
		draw_aim(m);
		aim_distance(m);
	}
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}
