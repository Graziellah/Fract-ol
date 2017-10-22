/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:51:44 by ghippoda          #+#    #+#             */
/*   Updated: 2017/03/07 03:10:25 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 500
# define WIDTH 500
# define RIGHT 124
# define LEFT 123
# define UP 126
# define Q 12
# define W 13
# define E 14
# define R 15
# define T 16
# define Y 17
# define DOWN 125
# define ESC 53
# define ZOOM_P 78
# define ZOOM_M 69
# define MOLLETTE_UP 4
# define MOLLETTE_DOWN 5
# define CLIC_LEFT 1
# define CLIC_DOWN 2
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define MOTIONNOTIFY 6
# define POINTERMOTIONMASK (1L<<6)
# define BUTTONPRESS 4
# define BUTTONPRESSMASK (1L<<2)
# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK  (1L<<17)
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <complex.h>

typedef struct				s_limit
{
	double					z_i;
	double					z_r;
	double					c_i;
	double					c_r;
	double					tmp;
	double					img_x;
	double					img_y;
}							t_complx;

typedef struct				s_coord
{
	int						x;
	int						y;
	int						z;
	int						color;
	int						proj;
}							t_coord;

typedef struct				s_info
{
	void					*mlx;
	void					*win;
	void					*img;
	int						img_2_win;
	char					*data;
	int						bpp;
	int						endian;
	int						szline;
	double					zoom;
	int						move_x;
	int						move_y;
	double					xmin;
	double					xmax;
	double					ymin;
	double					ymax;
	double					it_max;
	double					c_i;
	double					c_r;
	int						figure;
	int						julia;
	int						circle;
	int						color;
	double					ecart;
	int						loop;
}							t_info;

void						ft_draw_line(t_info *i, t_coord a, t_coord b);
int							ft_init_param(char *str);
void						mandelbrot(t_info *i);
void						burningship(t_info *i);
void						mandelbulb(t_info *i);
void						julia(t_info *i);
void						mandelbrot3(t_info *i);
void						mandelbrot4(t_info *i);
void						mandelbrot5(t_info *i);
void						tricorn(t_info *i);
void						graz(t_info *i);
void						circle_line(t_coord a, int t, t_info *i);
void						circle_infinit(t_coord a, int r, t_info *i);
void						mlx_pixel_put_to_image(t_info *i, int x,
		int y, int color);
void						multi_fract(void *mlx, t_info *a);
int							ft_mouse_hook(int button, int x, int y, t_info *i);
int							my_key_func(int keycode, t_info *i);
int							ft_mouse_hook_pointer(int x, int y, t_info *i);
void						ft_init_info(t_info *i);
int							ft_init_param2(char *str, char *str2);
void						fractal_lanch(t_info *i);
void						mlx_change(t_info *i);
int							wclose(t_info *i);
int							my_key_func(int keycode, t_info *i);
int							ft_mouse_hook(int button, int x, int y, t_info *i);
int							ft_mouse_hook_pointer(int x, int y, t_info *i);
void						stop_julia(t_info *i);
#endif
