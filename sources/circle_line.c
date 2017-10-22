/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:58:08 by ghippoda          #+#    #+#             */
/*   Updated: 2017/03/06 17:24:31 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		draw_circle(t_coord p, int r, t_info *i)
{
	double		a;

	a = 0;
	while (a < 360)
	{
		mlx_pixel_put_to_image(i, p.x + r * cos(a), p.y + r * sin(a), i->color);
		a = a + (2 * M_PI) / (8 * r);
	}
}

void		circle_line(t_coord a, int r, t_info *i)
{
	int		tmp_a;

	tmp_a = a.x;
	draw_circle(a, r, i);
	if (r > 2)
	{
		a.x = tmp_a + r;
		circle_line(a, r / 2, i);
		a.x = tmp_a - r;
		circle_line(a, r / 2, i);
	}
	if (r <= 1)
		return ;
}

void		circle_infinit(t_coord a, int r, t_info *i)
{
	int		tmp_a;

	tmp_a = a.x;
	draw_circle(a, r, i);
	if (r > 2)
	{
		a.x = tmp_a + r / 2;
		circle_infinit(a, r / 2, i);
		a.x = tmp_a - r / 2;
		circle_infinit(a, r / 2, i);
	}
}
