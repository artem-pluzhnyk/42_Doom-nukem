/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:24:24 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/15 17:12:17 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	draw_poster(t_main *m)
{
	unsigned	i;

	i = -1;
	while (++i < MAP.num_poster)
	{
		PIC[i].texture = PIC[i].texture;
		PIC[i].poz.x = PIC[i].poz.x;
		PIC[i].poz.y = PIC[i].poz.y;
	}
}
