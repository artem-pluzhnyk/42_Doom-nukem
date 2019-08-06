/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:14:54 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/05 17:20:11 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	load_font(t_main *m)
{
	if (!(SDL.ttf_50 = TTF_OpenFont("resources/font/SAMBD.ttf", 50)))
		ft_exit("☣ Error ☣");
	TTF_SetFontOutline(SDL.ttf_50, 1);
	TTF_SetFontKerning(SDL.ttf_50, 1);
	TTF_SetFontHinting(SDL.ttf_50, TTF_HINTING_NORMAL);
	if (!(SDL.ttf_28 = TTF_OpenFont("resources/font/SAMBD.ttf", 28)))
		ft_exit("☣ Error ☣");
}
