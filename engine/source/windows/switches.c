/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:17:53 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 19:22:25 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	switch_gravitation(t_main *m)
{
	SDL_Surface	*sur;
	SDL_Rect	rect;
	int			len;

	rect.x = WIN_W / 6;
	rect.y = WIN_H / 8;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_50, "Gravitation", SDL.yellow);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	TTF_SizeText(SDL.ttf_50, "Gravitation", &len, NULL);
	rect.h = SDL.texture[CFG.fly + 21]->h / 3;
	rect.w = SDL.texture[CFG.fly + 21]->w / 3;
	rect.x += len + rect.w / 2;
	SDL_BlitScaled(SDL.texture[CFG.fly + 21], NULL, SDL.sur, &rect);
	switch_gravitation2(m, rect);
}

void	switch_sky(t_main *m)
{
	SDL_Surface	*sur;
	SDL_Rect	rect;
	int			len;

	rect.x = WIN_W / 2;
	rect.y = WIN_H / 24;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_50, "Skybox", SDL.yellow);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	TTF_SizeText(SDL.ttf_50, "Skybox", &len, NULL);
	rect.h = SDL.texture[CFG.sky + 21]->h / 3;
	rect.w = SDL.texture[CFG.sky + 21]->w / 3;
	rect.x += len + rect.w / 2;
	SDL_BlitScaled(SDL.texture[CFG.sky + 21], NULL, SDL.sur, &rect);
	switch_sky2(m, rect);
}

void	switch_walls(t_main *m)
{
	SDL_Surface	*sur;
	SDL_Rect	rect;
	int			len;

	rect.x = WIN_W / 2;
	rect.y = WIN_H / 8;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_50, "Walls", SDL.yellow);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	TTF_SizeText(SDL.ttf_50, "Walls", &len, NULL);
	rect.h = SDL.texture[CFG.walls + 21]->h / 3;
	rect.w = SDL.texture[CFG.walls + 21]->w / 3;
	rect.x += len + rect.w / 2;
	SDL_BlitScaled(SDL.texture[CFG.walls + 21], NULL, SDL.sur, &rect);
	switch_walls2(m, rect);
}

void	switch_texture(t_main *m)
{
	SDL_Surface	*sur;
	SDL_Rect	rect;
	int			len;

	rect.x = WIN_W / 1.5;
	rect.y = WIN_H / 24;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_50, "Floor texture", SDL.yellow);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	TTF_SizeText(SDL.ttf_50, "Floor texture", &len, NULL);
	rect.h = SDL.texture[CFG.txtr + 21]->h / 3;
	rect.w = SDL.texture[CFG.txtr + 21]->w / 3;
	rect.x += len + rect.w / 2;
	SDL_BlitScaled(SDL.texture[CFG.txtr + 21], NULL, SDL.sur, &rect);
	switch_texture2(m, rect);
}

void	tall_towers(t_main *m)
{
	SDL_Surface	*sur;
	SDL_Rect	rect;
	int			len;

	rect.x = WIN_W / 1.5;
	rect.y = WIN_H / 8;
	rect.w = 0;
	rect.h = 0;
	sur = TTF_RenderText_Solid(SDL.ttf_50, "Tall Towers", SDL.yellow);
	SDL_BlitSurface(sur, NULL, SDL.sur, &rect);
	SDL_FreeSurface(sur);
	TTF_SizeText(SDL.ttf_50, "Tall Towers", &len, NULL);
	rect.h = SDL.texture[CFG.tall + 21]->h / 3;
	rect.w = SDL.texture[CFG.tall + 21]->w / 3;
	rect.x += len + rect.w / 2;
	SDL_BlitScaled(SDL.texture[CFG.tall + 21], NULL, SDL.sur, &rect);
	tall_towers2(m, rect);
}
