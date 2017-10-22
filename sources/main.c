/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 03:29:30 by ghippoda          #+#    #+#             */
/*   Updated: 2017/03/07 03:20:39 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	ft_putstr("usage : ./fractol fractol_number [option -fractol_number]\n");
	ft_putstr("option:\n 1 = Mandelbrot\n 2 = Julia\n");
	ft_putstr(" 3 = Mandelbrot3\n 4 = Graz\n 5 = Burning ship\n");
	ft_putstr(" 6 = Circle_line\n 7 = Circle_infinit\n 8 = Tricorn\n");
	ft_putstr(" 9 = Mandelbrot5\n 10 = Mandelbrot4\n");
}

void	control(void)
{
	ft_putstr("Controls\n");
	ft_putstr("Q = On fractal circle(6/7), moving zoom\n");
	ft_putstr("W = Change fractal\n");
	ft_putstr("E = Change color\n");
	ft_putstr("R = Reset setting\n");
	ft_putstr("T = Less iteration\n");
	ft_putstr("Y = More iteration\n");
	ft_putstr("CLIC = Zoom on circle's fractal\n");
	ft_putstr("SPACE = Stop julia move\n");
	ft_putstr("ARROW = Move the fractal\n");
	ft_putstr("SCROLL = Zoom\n");
}

int		main(int ac, char **av)
{
	if (ac == 2 && ft_atoi(av[1]) > 0 && ft_atoi(av[1]) < 11)
	{
		control();
		ft_init_param(av[1]);
	}
	else if (ac == 3 && ((ft_atoi(av[1]) > 0 && ft_atoi(av[1]) < 11) &&
				(ft_atoi(av[2]) > 0 && ft_atoi(av[2]) < 11)))
	{
		control();
		ft_init_param2(av[1], av[2]);
	}
	else
		error();
	return (0);
}
