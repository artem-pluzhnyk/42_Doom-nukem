/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_sdl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:36:36 by apluzhni          #+#    #+#             */
/*   Updated: 2019/07/30 15:17:40 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	events_sdl(t_main *m)
{
	if (SDL.event.key.type == SDL_KEYDOWN
	&& SDL.event.key.keysym.sym == SDLK_RETURN
	&& m->state == 0)
		m->state = 1;
	if (SDL.event.type == SDL_QUIT)
		escape(m);
	if (SDL.event.key.type == SDL_KEYDOWN
	&& SDL.event.key.keysym.sym == SDLK_ESCAPE)
	{
		if (m->state == 1 || !(m->state))
			escape(m);
		else
			m->state = 1;
	}
	events_sdl_moves(m);
	mouse_buttons(m);
}

void	events_sdl_moves(t_main *m)
{
	if (SDL.event.key.type == SDL_KEYUP || SDL.event.key.type == SDL_KEYDOWN)
	{
		if (SDL.event.key.keysym.sym == 'w')
			MOV.wsad[0] = SDL.event.type==SDL_KEYDOWN;
		if (SDL.event.key.keysym.sym == 's')
			MOV.wsad[1] = SDL.event.type==SDL_KEYDOWN;
		if (SDL.event.key.keysym.sym == 'a')
			MOV.wsad[2] = SDL.event.type==SDL_KEYDOWN;
		if (SDL.event.key.keysym.sym == 'd')
			MOV.wsad[3] = SDL.event.type==SDL_KEYDOWN;
		if (SDL.event.key.keysym.sym == ' ')
			if (MOV.ground)
			{
				USER.velocity.z += 0.5;
				MOV.falling = 1;
			}
		if (SDL.event.key.keysym.sym == SDLK_LCTRL
		|| SDL.event.key.keysym.sym == SDLK_RCTRL)
		{
			MOV.ducking = SDL.event.type==SDL_KEYDOWN;
			MOV.falling = 1;
		}
	}
}

void	mouse_rotation(t_main *m)
{
	int		x;
	int		y;

	SDL_GetRelativeMouseState(&x,&y);
	USER.angle += x * 0.01f;
	MOV.yaw = CLAMP(MOV.yaw + y * 0.02f, -5, 5);
	USER.yaw = MOV.yaw - USER.velocity.z * 0.5f;
	move_player(m, 0,0);
	MOV.move_vec[0] = 0.f;
	MOV.move_vec[1] = 0.f;

	if (MOV.wsad[0])
	{
		MOV.move_vec[0] += USER.anglecos * 0.1f;
		MOV.move_vec[1] += USER.anglesin * 0.1f;
	}
	if (MOV.wsad[1])
	{
		MOV.move_vec[0] -= USER.anglecos * 0.1f;
		MOV.move_vec[1] -= USER.anglesin * 0.1f;
	}
	if (MOV.wsad[2])
	{
		MOV.move_vec[0] += USER.anglesin * 0.1f;
		MOV.move_vec[1] -= USER.anglecos * 0.1f;
	}
	if (MOV.wsad[3])
	{
		MOV.move_vec[0] -= USER.anglesin * 0.1f;
		MOV.move_vec[1] += USER.anglecos * 0.1f;
	}

	MOV.pushing = MOV.wsad[0] || MOV.wsad[1] || MOV.wsad[2] || MOV.wsad[3];
	MOV.acceleration = MOV.pushing ? 0.4 : 0.2;
	USER.velocity.x = USER.velocity.x * (1 - MOV.acceleration) + MOV.move_vec[0] * MOV.acceleration;
	USER.velocity.y = USER.velocity.y * (1 - MOV.acceleration) + MOV.move_vec[1] * MOV.acceleration;

	if (MOV.pushing)
		MOV.moving = 1;
	SDL_Delay(10);
}
