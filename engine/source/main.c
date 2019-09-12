/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/12 17:40:04 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		main(void)
{
	t_main	m;

	load_settings(&m);
	init_sdl(&m);
	init_data(&m);
	load_textures(&m);
	load_font(&m);
	load_map(&m);
	load_sounds(&m);
	game_loop(&m);
	return (0);
}

void	escape(t_main *m)
{
	save_game(m);
	save_settings(m);
	SDL_DestroyWindow(SDL.win);
	TTF_CloseFont(SDL.ttf_50);
	TTF_CloseFont(SDL.ttf_28);
	TTF_Quit();
	SDL_Quit();
	Mix_FreeMusic(SDL.sound[0]);
	Mix_FreeMusic(SDL.sound[1]);
	exit(EXIT_SUCCESS);
}
