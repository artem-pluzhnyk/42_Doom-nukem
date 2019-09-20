/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:55:15 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 18:56:50 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	mouse_rotation(t_main *m)
{
	int		x;
	int		y;
	double	old_dir_x;
	double	old_plane_x;

	SDL_GetRelativeMouseState(&x, &y);
	move_sky(m, x, y);
	USER.angle += x * 0.03f;
	MOVE.yaw = CLAMP(MOVE.yaw + y * 0.05f, -5, 5);
	USER.yaw = MOVE.yaw - USER.velocity.z * 0.5f;
	move_player(m, 0, 0);
	MOVE.move_vec[0] = 0.f;
	MOVE.move_vec[1] = 0.f;
	old_dir_x = SREND.dir_x;
	SREND.dir_x = SREND.dir_x * cos(0.01f) - SREND.dir_y * sin(0.01f);
	SREND.dir_y = old_dir_x * sin(0.01f) + SREND.dir_y * cos(0.01f);
	old_plane_x = SREND.plane_x;
	SREND.plane_x = SREND.plane_x * cos(0.01f) - SREND.plane_y * sin(0.01f);
	SREND.plane_y = old_plane_x * sin(0.01f) + SREND.plane_y * cos(0.01f);
	mouse_rotation2(m);
	mouse_rotation3(m);
}

void	mouse_rotation2(t_main *m)
{
	if (MOVE.wsad[0])
	{
		MOVE.move_vec[0] += USER.anglecos * USER.speed;
		MOVE.move_vec[1] += USER.anglesin * USER.speed;
	}
	if (MOVE.wsad[1])
	{
		MOVE.move_vec[0] -= USER.anglecos * USER.speed;
		MOVE.move_vec[1] -= USER.anglesin * USER.speed;
	}
	if (MOVE.wsad[2])
	{
		MOVE.move_vec[0] += USER.anglesin * USER.speed;
		MOVE.move_vec[1] -= USER.anglecos * USER.speed;
	}
	if (MOVE.wsad[3])
	{
		MOVE.move_vec[0] -= USER.anglesin * USER.speed;
		MOVE.move_vec[1] += USER.anglecos * USER.speed;
	}
}

void	mouse_rotation3(t_main *m)
{
	MOVE.pushing = MOVE.wsad[0] || MOVE.wsad[1] || MOVE.wsad[2] || MOVE.wsad[3];
	MOVE.acceleration = MOVE.pushing ? 0.4 : 0.2;
	USER.velocity.x = USER.velocity.x * (1 - MOVE.acceleration) +
		MOVE.move_vec[0] * MOVE.acceleration;
	USER.velocity.y = USER.velocity.y * (1 - MOVE.acceleration) +
		MOVE.move_vec[1] * MOVE.acceleration;
	if (MOVE.pushing)
		MOVE.moving = 1;
	SDL_Delay(10);
}
