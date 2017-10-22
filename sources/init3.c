/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <ghippoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:22:37 by ghippoda          #+#    #+#             */
/*   Updated: 2017/03/07 03:12:00 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			wclose(t_info *i)
{
	mlx_destroy_image(i->mlx, i->img);
	mlx_destroy_window(i->mlx, i->win);
	exit(0);
	return (0);
}

void		ft_init_info(t_info *i)
{
	i->zoom = 125;
	i->xmin = -2;
	i->ymin = -2;
	i->xmax = 2;
	i->ymax = 2;
	i->it_max = 50;
	i->c_r = -1.0;
	i->c_i = 1;
	i->color = rand();
	i->circle = 150;
	i->loop = 0;
	i->julia = 0;
	i->ecart = (i->xmax - i->xmin);
}

void		stop_julia(t_info *i)
{
	if (i->julia == 1)
		i->julia = 0;
	else
		i->julia = 1;
}

int			ft_mouse_hook_pointer(int x, int y, t_info *i)
{
	if (x < HEIGHT && y < WIDTH && i->julia == 1)
	{
		i->c_i = (double)x / HEIGHT;
		i->c_r = (double)y / WIDTH;
	}
	mlx_change(i);
	return (0);
}
