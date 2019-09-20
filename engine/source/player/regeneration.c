/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regeneration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:36:10 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 15:34:16 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	healing_player(t_main *m)
{
	if (!(SECT[USER.sector].gas) && USER.armor <= 125)
		USER.armor += 0.05;
}

void	radiation(t_main *m)
{
	if (SECT[USER.sector].gas)
	{
		radiation_sign(m);
		if (USER.armor >= 0.5)
			USER.armor -= 0.5;
		else
			USER.health -= 1;
	}
}

void	radiation_sign(t_main *m)
{
	SDL_Rect	rect;

	rect.h = SDL.texture[23]->h;
	rect.w = SDL.texture[23]->w;
	rect.x = 0;
	rect.y = 0;
	SDL_BlitSurface(SDL.texture[23], NULL, SDL.sur, &rect);
}
