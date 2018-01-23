/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:05:15 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/23 12:02:11 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move(int key, t_win_info *w)
{
	if (key == 124)
	{
		w->x1 += (50 / SIZE * (w->x2 - w->x1));
		w->x2 += (50 / SIZE * (w->x2 - w->x1));
	}
	else if (key == 123)
	{
		w->x1 -= (50 / SIZE * ((w->x2 - w->x1)));
		w->x2 -= (50 / SIZE * ((w->x2 - w->x1)));
	}
	else if (key == 126)
	{
		w->y1 -= (50 / SIZE * ((w->y2 - w->y1)));
		w->y2 -= (50 / SIZE * ((w->y2 - w->y1)));
	}
	else if (key == 125)
	{
		w->y1 += (50 / SIZE * ((w->y2 - w->y1)));
		w->y2 += (50 / SIZE * ((w->y2 - w->y1)));
	}
}

static void	set_param(t_win_info *w)
{
	if (w->fractal == 1)
		set_param_mandelbrot(w);
	else if (w->fractal == 2)
		set_param_julia(w);
	else if (w->fractal == 3)
		set_param_burning_ship(w);
}

int			my_key_funct(int key, void *param)
{
	t_win_info *w;

	w = (t_win_info*)param;
	if ((key >= 123 && key <= 126) || key == 15 || key == 53 || key == 69 ||
	key == 78 || (key >= 17 && key <= 20))
	{
		if (key >= 123 && key <= 126)
			move(key, w);
		else if (key == 15)
			set_param(w);
		else if (key == 53)
			exit(0);
		else if (key == 69)
			w->imax += 10;
		else if (key == 78)
			w->imax -= 10;
		else if (key == 17)
			w->togle ^= 1;
		else if (key >= 18 && key <= 20)
			w->pal = set_pal(key);
		display_fract(w);
	}
	return (0);
}
