/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:49:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/08/04 14:32:34 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "../libft/include/libft.h"
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <glfw3.h>

# define WIN_FLG		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL // | SDL_WINDOW_RESIZABLE

# define SDL			m->sdl
# define CFG			m->cfg
# define SECT			m->sectors
# define USER			m->player
# define REND			m->rend
# define INTERSECT(m)	intersect(m);
# define IS				m->rend.is
# define MOV			m->moves
# define SCAL			m->rend.ty

# define WIN_W			CFG.window_width
# define WIN_H			CFG.window_height

# define EYE_H			6
# define DUCK_H			2.5
# define HEAD_MARG		1
# define KNEE_H			2
# define H_FOV			(0.73f * SDL.display.h)
# define V_FOV			(.2f * SDL.display.h)
# define MAXQUEUE		32
# define YAW(y, z)		(y + z * USER.yaw)

typedef struct		s_player
{
	t_xyz			where;
	t_xyz			velocity;
	float			angle;
	float			anglesin;
	float			anglecos;
	float			yaw;
	unsigned		sector;
}					t_player;

typedef struct		s_sector
{
	float			floor;
	float			ceil;
	t_xy			*vertex;
	signed char		*neighbors;
	unsigned		npoints;
}					t_sector;

typedef struct		s_intersect
{
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	float			x3;
	float			y3;
	float			x4;
	float			y4;
}					t_intersect;

typedef struct		s_item
{
	int				sectorno;
	int				sx1;
	int				sx2;
}					t_item;

typedef struct		s_scaler
{
	int				result;
	int				bop;
	int				fd;
	int				ca;
	int				cache;
}					t_scaler;

typedef struct		s_rend
{
	t_item			queue[MAXQUEUE];
	t_item			*head;
	t_item			*tail;
	int				*ytop;
	int				*ybottom;
	int				*rend_sect;
	t_item			now;
	t_sector const	*sect;
	float			vx1;
	float			vy1;
	float			vx2;
	float			vy2;
	float			pcos;
	float			psin;
	float			tx1;
	float			tz1;
	float			tx2;
	float			tz2;
	t_xy			i1;
	t_xy			i2;
	t_intersect		is;
	float			xscale1;
	float			yscale1;
	float			xscale2;
	float			yscale2;
	int				x1;
	int				x2;
	float			yceil;
	float			yfloor;
	int				neighbor;
	float			nyceil;
	float			nyfloor;
	int				y1a;
	int				y1b;
	int				y2a;
	int				y2b;
	int				ny1a;
	int				ny1b;
	int				ny2a;
	int				ny2b;
	int				beginx;
	int				endx;
	int				z;
	int				ya;
	int				cya;
	int				yb;
	int				cyb;
	int				nya;
	int				cnya;
	int				nyb;
	int				cnyb;
	unsigned		r1;
	unsigned		r2;
	int				u0;
	int				u1;
	t_xy			org1;
	t_xy			org2;
	int				txtx;
	int				txtr_id;
	t_scaler		ty;
}					t_rend;

typedef struct		s_move
{
	int				wsad[4];
	int				ground;
	int				falling;
	int				moving;
	int				ducking;
	float			yaw;
	float			eyeheight;
	float			nextz;
	float			px;
	float			py;
	float			dx;
	float			dy;
	t_sector		*sect;
	t_xy			*vert;
	float			hole_low;
	float			hole_high;
	float			xd;
	float			yd;
	float			move_vec[2];
	int				pushing;
	float			acceleration;
}					t_move;

typedef struct		s_cfg
{
	int				aim_enable;
	int				aim_size;
	unsigned		window_width;
	unsigned		window_height;
}					t_cfg;

typedef struct		s_sdl
{
	SDL_DisplayMode	display;
	SDL_Window		*win;
	SDL_Surface		*sur;
	SDL_Event		event;
	SDL_Surface		*txtr[10];
	SDL_Rect		rect[5];
	SDL_Rect		text_rect;
	SDL_Rect		back_rect;
	TTF_Font		*ttf;
	TTF_Font		*ttf2;
	SDL_Color		color;
}					t_sdl;

typedef struct		s_main
{
	t_sdl			sdl;
	t_cfg			cfg;
	unsigned		num_s;
	int				num_v;
	t_xy			*vert;
	t_sector		*sectors;
	t_player		player;
	int				state;
	int				dat_load;
	t_rend			rend;
	t_move			moves;
}					t_main;


/*
** main.c
*/
void				escape(t_main *m);

/*
** initialization/settings.c
*/
void				load_settings(t_main *m);
void				create_setings_file(t_main *m);

/*
** initialization/initialization.c
*/
void				initialization_sdl(t_main *m);
void				initialization_data(t_main *m);

/*
** initialization/load_resources.c
*/
void				load_textures(t_main *m);
void				load_font(t_main *m);

/*
** initialization/scan_map.c
*/
void				load_map(t_main *m);
void				read_data(t_main *m, int fd);

/*
** initialization/default_map.c
*/
void				create_map(t_main *m, char *file);
void				default_vertex(t_main *m, int fd);
void				default_sector(t_main *m, int fd);
void				default_player(t_main *m, int fd);

/*
** render/frames.c
*/
void				game_loop(t_main *m);
void				select_window(t_main *m);

/*
** render/pixels.c
*/
void				ft_put_pixel(t_main *m, int x, int y, int pixel);
int					ft_get_pixel(SDL_Surface *sur, int32_t x, int32_t y);
void				vline(t_main *m, int x, int y1, int y2, unsigned txtx);
void				draw_background(t_main *m);

/*
** render/additions.c
*/
t_xy				intersect(t_main *m);
int					scaler_next(t_scaler *i);
void				scaler_init(t_main *m, int a, int b, int c, int d, int f);

/*
** render/display1.c
*/
void				render_all(t_main *m);
void				render_loop(t_main *m);
void				render_npoints(t_main *m);
void				render_init1(t_main *m, unsigned s);

/*
** render/display2.c
*/
void				render_2(t_main *m);
void				render_init2(t_main *m);
void				render_init3(t_main *m);
void				render_init4(t_main *m, unsigned s);

/*
** render/display3.c
*/
void				render_startend(t_main *m);
void				render_init5(t_main *m, int x);
void				render_init6(t_main *m, int x);
void				render_last(t_main *m);

/*
** render/options.c
*/
void				options(t_main *m);

/*
** events/events_sdl.c
*/
void				events_sdl(t_main *m);
void				events_sdl_moves(t_main *m);
void				mouse_rotation(t_main *m);

/*
** events/moves.c
*/
void				move_player(t_main *m, float dx, float dy);
void				events(t_main *m);
void				event_falling(t_main *m);
void				event_moving(t_main *m);

/*
** events/mouse.c
*/
void				mouse_buttons(t_main *m);

/*
**  window/loading_screen.c
*/
void				loading_screen(t_main *m);
void				write_loading_text(t_main *m);

/*
** window/menu.c
*/
void				menu(t_main *m);
void				draw_button(t_main *m);
void				button_click(t_main *m);
void				button_text(t_main *m, int x, int y, int w, int h);

/*
** window/gameplay.c
*/
void				gameplay(t_main *m);

/*
** window/settings.c
*/
void				settings_window(t_main *m);

/*
** interface/aim.c
*/
int					draw_aim(t_main *m);
void				draw_aim_distance(t_main *m);

/*
** interface/hud.c
*/
void				draw_hud(t_main *m);

/*
** map_editor/map_editor.c
*/
void				map_editor(t_main *m);

#endif
