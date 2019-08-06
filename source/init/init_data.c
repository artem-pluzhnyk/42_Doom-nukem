/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:06:48 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/06 15:50:52 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_data(t_main *m)
{
	m->state = 0;
	SDL.white.r = 255;
	SDL.white.g = 255;
	SDL.white.b = 255;
	SDL.green.r = 255;
	SDL.green.g = 255;
	SDL.green.b = 255;
	SDL.red.r = 255;
	SDL.red.g = 255;
	SDL.red.b = 255;
	MOVE.wsad[0] = 0;
	MOVE.wsad[1] = 0;
	MOVE.wsad[2] = 0;
	MOVE.wsad[3] = 0;
	MOVE.ground = 0;
	MOVE.falling = 1;
	MOVE.moving = 0;
	MOVE.ducking = 0;
	MOVE.yaw = 0;
	HUD.hud = 1;
	HUD.aim = 0;
}
