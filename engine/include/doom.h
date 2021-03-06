/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apluzhni <apluzhni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:49:25 by apluzhni          #+#    #+#             */
/*   Updated: 2019/09/20 20:06:39 by apluzhni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include "../../libft/include/libft.h"
# include <SDL.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>

# define SDL		m->sdl
# define CFG		m->cfg
# define MAP		m->map
# define SECT		MAP.sectors
# define USER		MAP.player
# define OBJ		MAP.obj
# define PIC		MAP.pic
# define REND		m->rend
# define SREND		m->srend
# define IS			REND.is
# define SCAL		REND.ty
# define MOVE		m->move
# define HUD		m->hud

# define WIN_W		CFG.win_width
# define WIN_H		CFG.win_height

# define WIN_FLG	SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL

# define EYE_H		6
# define DUCK_H		2.5
# define HEAD_MARG	1
# define KNEE_H		2
# define MAXQUEUE	32
# define H_FOV		(0.73f * WIN_H)
# define V_FOV		(.2f * WIN_H)
# define HFOV		(1.0 * 0.73f * WIN_H / WIN_W)
# define VFOV		(1.0 * .2f)
# define YAW(y,z)	(y + z * USER.yaw)

typedef struct s_intersect	t_intersect;
typedef struct s_scaler		t_scaler;
typedef struct s_item		t_item;
typedef struct s_move		t_move;
typedef struct s_sector		t_sector;
typedef struct s_player		t_player;
typedef struct s_rend		t_rend;
typedef struct s_srend		t_srend;
typedef struct s_map		t_map;
typedef struct s_cfg		t_cfg;
typedef struct s_hud		t_hud;
typedef struct s_sdl		t_sdl;
typedef struct s_main		t_main;

struct				s_srend
{
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
};

struct				s_player
{
	t_xyz			where;
	t_xyz			velocity;
	float			angle;
	float			anglesin;
	float			anglecos;
	float			yaw;
	unsigned		sector;
	double			speed;
	double			health;
	double			armor;
	unsigned		spawn_sect;
	t_xyz			spawn;
	int				gun;
};

struct				s_sector
{
	float			floor;
	float			ceil;
	t_xy			*vertex;
	signed char		*neighbors;
	unsigned		npoints;
	int				*texture;
	int				gas;
	int				gun;
};

struct				s_map
{
	unsigned		num_v;
	unsigned		num_s;
	t_xy			*vert;
	t_sector		*sectors;
	t_player		player;
	char			*str;
	char			*str1;
	char			*str2;
};

struct				s_item
{
	int				sectorno;
	int				sx1;
	int				sx2;
};

struct				s_scaler
{
	int				result;
	int				bop;
	int				fd;
	int				ca;
	int				cache;
};

struct				s_intersect
{
	float			x1;
	float			y1;
	float			x2;
	float			y2;
	float			x3;
	float			y3;
	float			x4;
	float			y4;
};

struct				s_rend
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
	int				pel;
	float			hei;
	float			mapx;
	float			mapz;
	int				x;
	int				y;
	unsigned		txtx2;
	unsigned		txtz2;
};

struct				s_move
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
};

struct				s_cfg
{
	unsigned		win_width;
	unsigned		win_height;
	int				music;
	int				map;
	int				fly;
	int				sky;
	int				walls;
	int				txtr;
	int				tall;
};

struct				s_hud
{
	int				aim;
	int				hud;
};

struct				s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*sur;
	SDL_DisplayMode	display;
	SDL_Event		event;
	SDL_Surface		*texture[26];
	TTF_Font		*ttf_50;
	TTF_Font		*ttf_28;
	Mix_Music		*sound;
	Mix_Chunk		*fire;
	Mix_Chunk		*run;
	Mix_Chunk		*jump;
	SDL_Color		white;
	SDL_Color		green;
	SDL_Color		red;
	SDL_Color		blue;
	SDL_Color		yellow;
	SDL_Color		gray;
	SDL_Rect		rect;
	SDL_Rect		gun;
	SDL_Rect		view;
};

struct				s_main
{
	int				fd;
	t_sdl			sdl;
	t_cfg			cfg;
	t_map			map;
	t_rend			rend;
	t_move			move;
	int				state;
	t_hud			hud;
	t_srend			srend;
	int				map_tab;
	int				loaded_map;
};

/*
** ./##########################################################################|
*/

/*
** main.c
*/
void				escape(t_main *m);

/*
** ./init/#####################################################################|
*/

/*
** sdl_init.c
*/
void				init_sdl(t_main *m);

/*
** init_data.c
*/
void				init_data(t_main *m);
void				init_data1(t_main *m);
void				init_data2(t_main *m);

/*
** load_textures.c
*/
void				load_textures(t_main *m);
void				load_textures1(t_main *m);
void				load_textures2(t_main *m);

/*
** load_font.c
*/
void				load_font(t_main *m);
void				unload_font(t_main *m);

/*
** load_map.c
*/
void				load_map(t_main *m);
void				read_map(t_main *m);

/*
** load_sounds.c
*/
void				load_sounds(t_main *m);
void				unload_sounds(t_main *m);

/*
** default_map.c
*/
void				create_map(t_main *m, char *file);
void				default_vertex(t_main *m);
void				default_player(t_main *m);

/*
** default_sectors.c
*/
void				default_sectors(t_main *m);
void				default_sector0(t_main *m);
void				default_sector1(t_main *m);

/*
** ./settings/#################################################################|
*/

/*
** settings.c
*/
void				load_settings(t_main *m);
void				default_setings(t_main *m);
void				save_settings(t_main *m);

/*
** savegame.c
*/
void				save_game(t_main *m);

/*
** ./render/###################################################################|
*/

/*
** frames.c
*/
void				game_loop(t_main *m);
void				select_window(t_main *m);

/*
** display1.c
*/
void				render_all(t_main *m);
void				render_loop(t_main *m);
void				render_npoints(t_main *m);
void				render_init1(t_main *m, unsigned s);

/*
** display2.c
*/
void				render_2(t_main *m);
void				render_init2(t_main *m);
void				render_if(t_main *m);
void				render_init3(t_main *m);
void				render_init4(t_main *m, unsigned s);

/*
** display3.c
*/
void				render_startend(t_main *m, int s);
void				render_init6(t_main *m, int x);
void				render_last(t_main *m);
void				coord_to_texture(t_main *m, int x, int y);

/*
** display0.c
*/
void				render_init5(t_main *m, int x);
void				norm_kostyl1(t_main *m);
void				norm_kostyl2(t_main *m);
void				norm_kostyl3(t_main *m);
void				norm_kostyl4(t_main *m);

/*
** pixels.c
*/
void				ft_put_pixel(t_main *m, int x, int y, int pixel);
int					ft_get_pixel(SDL_Surface *sur, int32_t x, int32_t y);
void				vline(t_main *m, int x, int y1, int y2);
void				draw_background(t_main *m, SDL_Surface *sur);

/*
** additions.c
*/
t_xy				intersect(t_main *m);
void				scaler_init(t_main *m, int a, int b, int c);
int					scaler_next(t_scaler *i);
float				percentage(int start, int end, int curr);
int					color_transoform(int color, float percent);

/*
** ./windows/##################################################################|
*/

/*
** gameplay.c
*/
void				gameplay(t_main *m);
void				features(t_main *m);

/*
** loading_screen.c
*/
void				loading_screen(t_main *m);
void				loading_text(t_main *m);

/*
** menu.c
*/
void				menu(t_main *m);
void				play_btn(t_main *m);
void				setting_btn(t_main *m);
void				start_game(t_main *m, SDL_Rect rect);

/*
** settings.c
*/
void				settings_window(t_main *m);
void				map_choose(t_main *m);
void				switch_music(t_main *m);
void				screen_resolution(t_main *m);

/*
** switches.c
*/
void				switch_gravitation(t_main *m);
void				switch_sky(t_main *m);
void				switch_walls(t_main *m);
void				switch_texture(t_main *m);
void				tall_towers(t_main *m);

/*
** switches2.c
*/
void				switch_gravitation2(t_main *m, SDL_Rect rect);
void				switch_sky2(t_main *m, SDL_Rect rect);
void				switch_walls2(t_main *m, SDL_Rect rect);
void				switch_texture2(t_main *m, SDL_Rect rect);
void				tall_towers2(t_main *m, SDL_Rect rect);

/*
** endgame.c
*/
void				endgame(t_main *m);
void				endreturn(t_main *m);

/*
** ./events/###################################################################|
*/

/*
** events_sdl.c
*/
void				events_sdl(t_main *m);
void				events_moves(t_main *m);
void				mouse_buttons(t_main *m);
void				key(t_main *m);

/*
** events.c
*/
void				events(t_main *m);
void				move_player(t_main *m, float dx, float dy);
void				event_falling(t_main *m);

/*
** event_moving.c
*/
void				event_moving(t_main *m);
void				event_moving2(t_main *m, unsigned s);
void				event_moving3(t_main *m, unsigned s);

/*
** mouse_rotation.c
*/
void				mouse_rotation(t_main *m);
void				mouse_rotation2(t_main *m);
void				mouse_rotation3(t_main *m);

/*
** ./interface/################################################################|
*/

/*
** aim.c
*/
void				main_aim(t_main *m);

/*
** aiming.c
*/
void				aim_distance(t_main *m);
void				draw_aim(t_main *m);

/*
** hud.c
*/
void				draw_hud(t_main *m);
void				draw_hud_back(t_main *m);

/*
** gun.c
*/
void				draw_gun(t_main *m);
void				gun_animation(t_main *m);

/*
** skybox.c
*/
void				draw_sky(t_main *m);
void				move_sky(t_main *m, int x, int y);

/*
** ./##########################################################################|
*/

/*
** regeneration.c
*/
void				healing_player(t_main *m);
void				radiation(t_main *m);
void				radiation_sign(t_main *m);

#endif
