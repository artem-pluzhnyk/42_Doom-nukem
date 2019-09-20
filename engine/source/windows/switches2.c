/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:17:53 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 19:26:15 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	switch_gravitation2(t_main *m, SDL_Rect rect)
{
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	{
		CFG.fly = CFG.fly ? 0 : 1;
		SDL_Delay(100);
	}
}

void	switch_sky2(t_main *m, SDL_Rect rect)
{
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	{
		CFG.sky = CFG.sky ? 0 : 1;
		SDL_Delay(100);
	}
}

void	switch_walls2(t_main *m, SDL_Rect rect)
{
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	{
		CFG.walls = CFG.walls ? 0 : 1;
		SDL_Delay(100);
	}
}

void	switch_texture2(t_main *m, SDL_Rect rect)
{
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	{
		CFG.txtr = CFG.txtr ? 0 : 1;
		SDL_Delay(100);
	}
}

void	tall_towers2(t_main *m, SDL_Rect rect)
{
	if (SDL.event.type == SDL_MOUSEBUTTONDOWN
	&& SDL.event.button.button == SDL_BUTTON_LEFT
	&& SDL.event.button.x >= rect.x
	&& SDL.event.button.x <= (rect.x + rect.w)
	&& SDL.event.button.y >= rect.y
	&& SDL.event.button.y <= (rect.x + rect.h))
	{
		CFG.tall = CFG.tall ? 0 : 1;
		SDL_Delay(100);
	}
}
