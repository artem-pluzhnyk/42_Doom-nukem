/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:06:48 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/14 17:20:46 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_data(t_main *m)
{
	m->state = 0;
	SDL.white.r = 255;
	SDL.white.g = 255;
	SDL.white.b = 255;
	SDL.green.r = 0;
	SDL.green.g = 255;
	SDL.green.b = 0;
	SDL.red.r = 255;
	SDL.red.g = 0;
	SDL.red.b = 0;
	SDL.blue.r = 0;
	SDL.blue.g = 0;
	SDL.blue.b = 255;
	SDL.yellow.r = 255;
	SDL.yellow.g = 255;
	SDL.yellow.b = 0;
	SDL.gray.r = 100;
	SDL.gray.g = 100;
	SDL.gray.b = 100;
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
	SREND.dir_x = -1;
	SREND.dir_y = 0;
	SREND.plane_x = 0;
	SREND.plane_y = 0.66;
	USER.speed = 0.3f;
	USER.health = 100;
	USER.armor = 125;
	SDL.gun.x = 0;
}
