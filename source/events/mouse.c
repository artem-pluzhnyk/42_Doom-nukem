/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:29:24 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/27 13:27:17 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	mouse_buttons(t_main *m)
{
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (SDL.event.button.button == SDL_BUTTON_LEFT)
			; // fire and damage info
		if (SDL.event.button.button == SDL_BUTTON_RIGHT)
			CFG.aim_enable = CFG.aim_enable ? 0 : 1;
	}
}
