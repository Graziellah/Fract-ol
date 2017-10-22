/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <ghippoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:22:37 by ghippoda          #+#    #+#             */
/*   Updated: 2017/03/15 22:21:00 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		fractal_lanch(t_info *i)
{
	t_coord		a;

	a.x = 250;
	a.y = 250;
	if (i->figure == 1)
		mandelbrot(i);
	else if (i->figure == 2)
		julia(i);
	else if (i->figure == 3)
		mandelbrot3(i);
	else if (i->figure == 4)
		graz(i);
	else if (i->figure == 5)
		burningship(i);
	else if (i->figure == 6)
		circle_line(a, i->circle, i);
	else if (i->figure == 7)
		circle_infinit(a, i->circle, i);
	else if (i->figure == 8)
		tricorn(i);
	else if (i->figure == 9)
		mandelbrot5(i);
	else if (i->figure == 10)
		mandelbrot4(i);
}

void		mlx_change(t_info *i)
{
	bzero(i->data, HEIGHT * WIDTH * 4);
	fractal_lanch(i);
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
}

void		init_mlx(t_info *i)
{
	i->win = mlx_new_window(i->mlx, HEIGHT, WIDTH, "fract'ol");
	i->img = mlx_new_image(i->mlx, HEIGHT, WIDTH);
	i->data = mlx_get_data_addr(i->img, &(i->bpp), &(i->szline), &(i->endian));
}

int			ft_init_param2(char *str, char *str2)
{
	t_info	i;
	t_info	a;

	if (!(i.mlx = mlx_init()))
		return (0);
	a.mlx = i.mlx;
	init_mlx(&i);
	init_mlx(&a);
	ft_init_info(&i);
	ft_init_info(&a);
	i.figure = ft_atoi(str);
	a.figure = ft_atoi(str2);
	fractal_lanch(&i);
	fractal_lanch(&a);
	mlx_mouse_hook(i.win, ft_mouse_hook, &i);
	mlx_mouse_hook(a.win, ft_mouse_hook, &a);
	mlx_hook(i.win, KEYPRESS, KEYPRESSMASK, my_key_func, &i);
	mlx_hook(a.win, KEYPRESS, KEYPRESSMASK, my_key_func, &a);
	mlx_hook(i.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_mouse_hook_pointer, &i);
	mlx_hook(a.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_mouse_hook_pointer, &a);
	mlx_put_image_to_window(i.mlx, i.win, i.img, 0, 0);
	mlx_put_image_to_window(a.mlx, a.win, a.img, 0, 0);
	mlx_loop(i.mlx);
	return (0);
}

int			ft_init_param(char *str)
{
	t_info	i;

	if (!(i.mlx = mlx_init()))
		return (0);
	i.figure = ft_atoi(str);
	i.win = mlx_new_window(i.mlx, HEIGHT, WIDTH, "fract'ol");
	i.img = mlx_new_image(i.mlx, HEIGHT, WIDTH);
	i.data = mlx_get_data_addr(i.img, &(i.bpp), &(i.szline), &(i.endian));
	ft_init_info(&i);
	fractal_lanch(&i);
	mlx_mouse_hook(i.win, ft_mouse_hook, &i);
	mlx_hook(i.win, KEYPRESS, KEYPRESSMASK, my_key_func, &i);
	mlx_hook(i.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_mouse_hook_pointer, &i);
	mlx_hook(i.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close, &i);
	mlx_put_image_to_window(i.mlx, i.win, i.img, 0, 0);
	mlx_loop(i.mlx);
	return (0);
}
