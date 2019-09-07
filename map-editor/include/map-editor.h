/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-editor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrivosh <akrivosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:35:57 by akrivosh          #+#    #+#             */
/*   Updated: 2019/09/07 18:13:57 by akrivosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <SDL.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>

# define SDL		m->sdl

# define WIN_W		1500
# define WIN_H		1000

# define WIN_FLG	SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL

# define GRAY		0x808080

typedef struct s_sdl		t_sdl;
typedef struct s_main		t_main;

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
};

void				init_sdl(t_main *m);
void				loop(t_main *m);
void				map_editor(t_main *m);
void				draw_grid(t_main *m);
void				map_tabs(t_main *m);
void				ft_put_pixel(t_main *m, int x, int y, int pixel);
