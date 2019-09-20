/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_sdl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:53:58 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 15:30:14 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	events_sdl(t_main *m)
{
	if (SDL.event.key.type == SDL_KEYDOWN
	&& SDL.event.key.keysym.sym == SDLK_RETURN
	&& m->state == 0)
	{
		m->state = 1;
		SDL_Delay(100);
	}
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
	events_moves(m);
	mouse_buttons(m);
}

void	mouse_buttons(t_main *m)
{
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN && m->state == 2 && USER.gun)
	{
		if (SDL.event.button.button == SDL_BUTTON_LEFT)
		{
			if (!(Mix_Playing(3)))
				Mix_PlayChannel(3, SDL.fire, 0);
			if (HUD.hud)
				gun_animation(m);
		}
		if (SDL.event.button.button == SDL_BUTTON_RIGHT)
		{
			HUD.hud = HUD.hud ? 0 : 1;
			HUD.aim = HUD.aim ? 0 : 1;
		}
	}
}

void	events_moves(t_main *m)
{
	if ((SDL.event.key.type == SDL_KEYUP
	|| SDL.event.key.type == SDL_KEYDOWN)
	&& m->state == 2)
	{
		key(m);
		if (SDL.event.key.keysym.sym == ' ')
			if (MOVE.ground)
			{
				USER.velocity.z += 0.5;
				MOVE.falling = 1;
				if (!(Mix_Playing(3)))
					Mix_PlayChannel(3, SDL.jump, 0);
			}
		if (SDL.event.key.keysym.sym == SDLK_LCTRL
		|| SDL.event.key.keysym.sym == SDLK_RCTRL)
		{
			MOVE.ducking = SDL.event.type == SDL_KEYDOWN;
			MOVE.falling = 1;
		}
	}
}

void	key(t_main *m)
{
	if (SDL.event.key.keysym.sym == 'w')
		MOVE.wsad[0] = SDL.event.type == SDL_KEYDOWN;
	if (SDL.event.key.keysym.sym == 's')
		MOVE.wsad[1] = SDL.event.type == SDL_KEYDOWN;
	if (SDL.event.key.keysym.sym == 'a')
		MOVE.wsad[2] = SDL.event.type == SDL_KEYDOWN;
	if (SDL.event.key.keysym.sym == 'd')
		MOVE.wsad[3] = SDL.event.type == SDL_KEYDOWN;
	if (SDL.event.key.keysym.sym == SDLK_LSHIFT)
	{
		USER.speed = SDL.event.type == SDL_KEYDOWN ? 0.6f : 0.3f;
		if (!(Mix_Playing(3)))
			Mix_PlayChannel(3, SDL.run, 0);
	}
}
