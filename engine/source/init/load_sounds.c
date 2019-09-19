/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sounds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:50:28 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/19 19:28:50 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_sounds(t_main *m)
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 1024);
	SDL.sound = Mix_LoadMUS("../resources/music/soundtrack.mp3");
	SDL.fire = Mix_LoadWAV("../resources/sounds/shot.wav");
	SDL.jump = Mix_LoadWAV("../resources/sounds/jump.wav");
	SDL.run = Mix_LoadWAV("../resources/sounds/run.wav");
}
