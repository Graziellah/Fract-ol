/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:29:38 by ghippoda          #+#    #+#             */
/*   Updated: 2017/03/06 23:07:14 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_iterm3(t_complx *p, t_info *e, int x, int y)
{
	int		i;

	p->c_r = x / e->zoom + e->xmin;
	p->c_i = y / e->zoom + e->ymin;
	p->z_r = 0;
	p->z_i = 0;
	p->tmp = p->z_r;
	p->z_r = (p->z_r * p->z_r) - (p->z_i * p->z_i) + p->c_r;
	p->z_i = 2 * p->z_i * p->tmp + p->c_i;
	i = 1;
	while (p->z_r * p->z_r + p->z_i * p->z_i < 4 && i < e->it_max)
	{
		p->tmp = p->z_r;
		p->z_r = p->z_r * p->z_r * p->z_r - 3 * p->z_r * p->z_i * p->z_i
			+ p->c_r;
		p->z_i = 3 * p->tmp * p->tmp * p->z_i - p->z_i * p->z_i * p->z_i
			+ p->c_i;
		i++;
	}
	return (i);
}

void		mandelbrot3(t_info *e)
{
	int			i;
	int			x;
	int			y;
	t_complx	p;

	x = 0;
	p.img_x = (e->xmax - e->xmin) * e->zoom;
	p.img_y = (e->ymax - e->ymin) * e->zoom;
	while (x < p.img_x)
	{
		y = 0;
		while (y < p.img_y)
		{
			i = ft_iterm3(&p, e, x, y);
			if (i != e->it_max)
				mlx_pixel_put_to_image(e, x, y, i * e->color);
			y++;
		}
		x++;
	}
}
