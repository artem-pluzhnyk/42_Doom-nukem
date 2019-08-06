/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:45:51 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/06 15:18:03 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	game_loop(t_main *m)
{
	while (1)
	{
		SDL_FillRect(SDL.sur, NULL, 0x000000);
		select_window(m);
		while (SDL_PollEvent(&SDL.event))
			events_sdl(m);
		SDL_UpdateWindowSurface(SDL.win);
		events(m);
	}
}

void	select_window(t_main *m)
{
	if (m->state == 0)
		loading_screen(m);
	if (m->state == 1)
		menu(m);
	if (m->state == 3)
		settings_window(m);
	if (m->state == 4)
		map_editor(m);
	if (m->state == 2)
		gameplay(m);
}
