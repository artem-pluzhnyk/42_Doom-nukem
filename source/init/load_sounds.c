/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sounds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:50:28 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/01 17:35:05 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_sounds(t_main *m)
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 1024);
	SDL.sound[0] = Mix_LoadMUS("resources/music/soundtrack.mp3");
	Mix_PlayMusic(SDL.sound[0], -1);
}
