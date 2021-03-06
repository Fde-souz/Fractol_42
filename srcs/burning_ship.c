/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:11:47 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/23 12:36:51 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc(t_fract *f, t_win_info *w, int x, int y)
{
	int i;
	int color;

	f->cr = screento_cr(x, *w);
	f->ci = screento_ci(y, *w);
	f->zr = 0;
	f->zi = 0;
	i = 0;
	while (((f->zr * f->zr) + (f->zi * f->zi) < 4) && i < w->imax)
	{
		f->tmpr = f->zr;
		f->zr = fabs((f->zr * f->zr - f->zi * f->zi + f->cr));
		f->zi = fabs((f->tmpr * f->zi * 2 + f->ci));
		i++;
	}
	if (i != w->imax)
	{
		color = i % w->pal.nb;
		put_pixel_image(x, y, w->pal.pal[color], w);
	}
	else
		put_pixel_image(x, y, 0, w);
}

void		burning_ship(t_win_info *w)
{
	t_fract	f;
	int		x;
	int		y;

	x = 0;
	while (x < SIZE)
	{
		y = 0;
		while (y < SIZE)
		{
			calc(&f, w, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(w->mlx, w->win, w->ima, 0, 0);
}

void		set_param_burning_ship(t_win_info *w)
{
	w->x1 = -2;
	w->x2 = 2;
	w->y1 = -2.2;
	w->y2 = 2.2;
}
