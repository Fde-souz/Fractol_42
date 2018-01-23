/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:22:56 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/23 12:50:09 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			selec_fract(char *str, t_win_info *w)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		w->fractal = 1;
		set_param_mandelbrot(w);
		return (1);
	}
	else if (ft_strcmp(str, "julia") == 0)
	{
		w->fractal = 2;
		set_param_julia(w);
		return (1);
	}
	else if (ft_strcmp(str, "burning_ship") == 0)
	{
		w->fractal = 3;
		set_param_burning_ship(w);
		return (1);
	}
	return (0);
}

void		display_fract(t_win_info *w)
{
	if (w->fractal == 1)
	{
		mandelbrot(w);
	}
	else if (w->fractal == 2)
	{
		julia(w);
	}
	else if (w->fractal == 3)
	{
		burning_ship(w);
	}
}

static void	usage(void)
{
	ft_putendl("usage: fractol [mandelbrot, julia, burning_ship]");
	exit(0);
}

int			main(int ac, char **av)
{
	t_win_info w;

	if (ac != 2)
		usage();
	if (!(selec_fract(av[1], &w)))
		usage();
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, SIZE, SIZE, "fractol");
	w.ima = mlx_new_image(w.mlx, SIZE, SIZE);
	w.str = mlx_get_data_addr(w.ima, &w.bpp, &w.sl, &w.e);
	w.imax = 100;
	w.pal = set_pal(18);
	w.m_x = 0;
	w.m_y = 0;
	w.togle = 1;
	display_fract(&w);
	mlx_hook(w.win, 2, 1L << 0, my_key_funct, &w);
	mlx_hook(w.win, 6, 1L << 6, my_mouse_move, &w);
	mlx_mouse_hook(w.win, mouse_hook, &w);
	mlx_loop(w.mlx);
}
