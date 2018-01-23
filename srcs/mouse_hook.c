/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:19:25 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/23 11:55:47 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int button, double x, double y, t_win_info *w)
{
	if (button == 4)
	{
		w->x1 = x + ((w->x1 - x) / 2);
		w->x2 = w->x2 + ((x - w->x2) / 2);
		w->y1 = y + ((w->y1 - y) / 2);
		w->y2 = w->y2 + ((y - w->y2) / 2);
	}
	else if (button == 5)
	{
		w->x1 -= (w->x2 - w->x1) / 2;
		w->x2 += (w->x2 - w->x1) / 2;
		w->y1 -= (w->y2 - w->y1) / 2;
		w->y2 += (w->y2 - w->y1) / 2;
	}
}

int			mouse_hook(int button, int x, int y, void *param)
{
	t_win_info	*w;
	double		lx;
	double		ly;

	w = (t_win_info*)param;
	lx = screento_cr(x, *w);
	ly = screento_ci(y, *w);
	if (button >= 4 && button <= 5)
	{
		zoom(button, lx, ly, w);
		display_fract(w);
	}
	return (0);
}

int			my_mouse_move(int x, int y, void *param)
{
	t_win_info	*w;

	w = (t_win_info*)param;
	if (w->fractal == 2 && w->togle == 1)
	{
		w->m_x = x;
		w->m_y = y;
		display_fract(w);
	}
	return (0);
}
