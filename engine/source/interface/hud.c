/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:22:00 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/09 18:35:16 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_hud(t_main *m)
{
	SDL_Rect	health;
	SDL_Rect	armor;

	draw_hud_back(m);
	health.w = (int)USER.health * 3;
	health.h = WIN_H / 66;
	health.x = WIN_W - 400;
	health.y = health.h * 1.5;
	SDL_FillRect(SDL.sur, &health, 0xFF0000);
	armor.w = (int)USER.armor * 3;
	armor.h = WIN_H / 66;
	armor.x = WIN_W - 400;
	armor.y = armor.h * 1.5 + health.y;
	SDL_FillRect(SDL.sur, &armor, 0xCACACA);
}

void	draw_hud_back(t_main *m)
{
	SDL_Rect	rect1;
	SDL_Rect	rect2;

	rect1.w = 300;
	rect1.h = WIN_H / 66;
	rect1.x = WIN_W - 400;
	rect1.y = rect1.h * 1.5;
	rect2.w = 375;
	rect2.h = WIN_H / 66;
	rect2.x = WIN_W - 400;
	rect2.y = rect2.h * 1.5 + rect1.y;
	SDL_FillRect(SDL.sur, &rect1, 0x424242);
	SDL_FillRect(SDL.sur, &rect2, 0x424242);
}
