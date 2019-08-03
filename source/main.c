/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:43:23 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/02 11:00:50 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		main(void)
{
	t_main	*m;

	m = (t_main*)malloc(sizeof(t_main));
	load_settings(m);
	initialization_sdl(m);
	initialization_data(m);
	load_textures(m);
	load_font(m);
	load_map(m);
	game_loop(m);
	return (0);
}

void	escape(t_main *m)
{
	SDL_DestroyWindow(SDL.win);
	TTF_CloseFont(SDL.ttf);
	TTF_Quit();
	SDL_Quit();
	exit(EXIT_SUCCESS);
}
