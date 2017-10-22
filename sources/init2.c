/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <ghippoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:22:37 by ghippoda          #+#    #+#             */
/*   Updated: 2017/03/07 03:10:36 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_loop(t_info *i)
{
	if (i->loop == 1)
		i->circle *= 1.01;
	mlx_change(i);
	return (0);
}

void		move(int keycode, t_info *i)
{
	if (keycode == RIGHT)
	{
		i->xmin -= i->ecart / 100;
		i->xmax -= i->ecart / 100;
	}
	else if (keycode == LEFT)
	{
		i->xmin += i->ecart / 100;
		i->xmax += i->ecart / 100;
	}
	else if (keycode == UP)
	{
		i->ymin += i->ecart / 100;
		i->ymax += i->ecart / 100;
	}
	else if (keycode == DOWN)
	{
		i->ymin -= i->ecart / 100;
		i->ymax -= i->ecart / 100;
	}
}

int			my_key_func(int keycode, t_info *i)
{
	if (keycode == ESC)
		wclose(i);
	else if (keycode == RIGHT || keycode == LEFT || keycode == UP
			|| keycode == DOWN)
		move(keycode, i);
	else if (keycode == R)
		ft_init_info(i);
	else if (keycode == W)
		i->figure < 10 ? i->figure++ : (i->figure = 1);
	else if (keycode == Q && (i->figure == 7 || i->figure == 6))
	{
		i->loop = (i->loop) ? 0 : 1;
		if (i->loop == 1)
			mlx_loop_hook(i->mlx, &ft_loop, i);
	}
	else if (keycode == T)
		i->it_max += 5;
	else if (keycode == Y)
		i->it_max > 5 ? (i->it_max -= 5) : (i->it_max = 5);
	else if (keycode == E)
		i->color = rand();
	else if (keycode == 49 && i->figure == 2)
		stop_julia(i);
	mlx_change(i);
	return (0);
}

void		mouse_hook_circle(int button, t_info *i)
{
	if (button == CLIC_LEFT || button == MOLLETTE_UP)
		i->circle += 10;
	else if (button == CLIC_DOWN || button == MOLLETTE_DOWN)
		i->circle >= 10 ? i->circle -= 10 : 10;
}

int			ft_mouse_hook(int btn, int x, int y, t_info *i)
{
	double		ecart;

	if ((i->figure == 7 || i->figure == 6))
		mouse_hook_circle(btn, i);
	if (btn == MOLLETTE_UP)
	{
		i->zoom *= 1.1;
		ecart = (i->xmax - i->xmin) - (HEIGHT / i->zoom);
		i->xmin += ((double)x / HEIGHT) * ecart;
		i->xmax -= ((HEIGHT - (double)x) / HEIGHT) * ecart;
		i->ymin += ((double)y / WIDTH) * ecart;
		i->ymax -= ((WIDTH - (double)y) / WIDTH) * ecart;
	}
	if (btn == MOLLETTE_DOWN && (i->xmin >= -2 && i->xmax <= 2 &&
				i->ymin >= -2 && i->ymax <= 2))
	{
		i->zoom /= 1.1;
		ecart = (HEIGHT / i->zoom) + (-i->xmax + i->xmin);
		i->xmin -= ((double)x / HEIGHT) * ecart;
		i->xmax += ((HEIGHT - (double)x) / HEIGHT) * ecart;
		i->ymin -= ((double)y / WIDTH) * ecart;
		i->ymax += ((WIDTH - (double)y) / WIDTH) * ecart;
	}
	mlx_change(i);
	return (0);
}
