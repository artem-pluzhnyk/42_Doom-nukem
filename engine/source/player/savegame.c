/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savegame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:11:49 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/09 19:17:27 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "doom.h"

void	save_game(t_main *m)
{
	write(m->fd, &USER, sizeof(t_player));
}
