/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_editor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <akrivosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:36:18 by isavchen          #+#    #+#             */
/*   Updated: 2019/09/20 17:26:39 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_EDITOR_H
# define MAP_EDITOR_H
# include <SDL.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
#include "../../libft/include/libft.h"

# define SDL		m->sdl

# define WIN_W		1500
# define WIN_H		1000

# define WIN_FLG	SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL

# define GRAY		0x808080
# define RED					0xFF0000
typedef struct s_sdl		t_sdl;
typedef struct s_map		t_map;
typedef struct s_main		t_main;
typedef struct s_vert		t_vert;

struct				s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*sur;
	SDL_DisplayMode	display;
	SDL_Event		event;
	TTF_Font		*ttf;
	SDL_Color		white;
	SDL_Color		yellow;
};

struct				s_main
{
	t_sdl			sdl;
	int				map_tab;
	int				num_v;
	t_vert			*head;
	t_vert			*last;
};

struct				s_vert
{
	t_xy			xy;
	t_vert			*next;
};

void				init_sdl(t_main *m);
void				loop(t_main *m);
void				map_editor(t_main *m);
void				draw_grid(t_main *m);
void				map_tabs(t_main *m);
void				map_tabs2(t_main *m, SDL_Rect rect);
void				ft_put_pixel(t_main *m, int x, int y, int pixel);
void				coord(t_main *m);
void				draw_points(t_main *m);
#endif
