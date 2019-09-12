/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regeneration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:36:10 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/11 18:40:54 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "doom.h"

void	healing_player(t_main *m)
{
	if (!(SECT[USER.sector].gas) && USER.armor <= 125)
		USER.armor += 0.05;
}

void	radiation(t_main *m)
{
	if (SECT[USER.sector].gas)
	{
		if (USER.armor >= 0.5)
			USER.armor -= 0.5;
		else
			USER.health -= 1;
	}
}
