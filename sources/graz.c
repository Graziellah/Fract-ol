/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:29:38 by ghippoda          #+#    #+#             */
/*   Updated: 2017/03/06 23:06:06 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_iterj2(t_complx *p, t_info *e, int x, int y)
{
	int			i;

	p->c_r = 0.285;
	p->c_i = 0.01;
	p->z_r = x / e->zoom + e->xmin;
	p->z_i = y / e->zoom + e->ymin;
	p->tmp = p->z_r;
	p->z_r = (p->z_r * p->z_r) - (p->z_i * p->z_i) + p->c_r;
	p->z_i = 2 * p->z_i * p->tmp + p->c_i;
	i = 1;
	while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && i < e->it_max)
	{
		p->tmp = p->z_r;
		p->z_r = p->z_r * p->z_r - p->z_i * p->z_i + p->c_r;
		p->z_i = 2 * p->z_i * p->tmp + p->c_i;
		i++;
	}
	return (i);
}

void			graz(t_info *e)
{
	t_complx		p;
	int				i;
	int				x;
	int				y;

	x = 0;
	p.img_x = (e->xmax - e->xmin) * e->zoom;
	p.img_y = (e->ymax - e->ymin) * e->zoom;
	while (x < p.img_x)
	{
		y = 0;
		while (y < p.img_y)
		{
			i = ft_iterj2(&p, e, x, y);
			if (i != e->it_max)
				mlx_pixel_put_to_image(e, x, y, i * e->color);
			y++;
		}
		x++;
	}
}
