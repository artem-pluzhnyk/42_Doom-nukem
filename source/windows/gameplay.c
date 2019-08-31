/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:21:17 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/31 13:09:43 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	gameplay(t_main *m)
{
	render_all(m);
	// draw_poster(m); // Posters
	// draw_sprite(m); // Sprites
	if (HUD.hud)
		;//draw_hud(m, SDL.texture[5]);
	else
	{
		draw_hud(m, SDL.texture[4]);
		aim_distance(m);
	}
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}
