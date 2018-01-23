/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:53:57 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/22 17:13:20 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc(t_fract *f, t_win_info *w, int x, int y)
{
	int i;
	int color;

	f->cr = ((SIZE / 2 - w->m_x) / SIZE) * 2;
	f->ci = ((SIZE - w->m_y) / SIZE);
	f->zr = screento_cr(x, *w);
	f->zi = screento_ci(y, *w);
	i = 0;
	while (((f->zr * f->zr) + (f->zi * f->zi) < 4) && i < w->imax)
	{
		f->tmpr = f->zr;
		f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
		f->zi = 2 * f->tmpr * f->zi + f->ci;
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

void		julia(t_win_info *w)
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

void		set_param_julia(t_win_info *w)
{
	w->x1 = -1;
	w->x2 = 1;
	w->y1 = -1.2;
	w->y2 = 1.2;
}
