/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:07:22 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/22 11:07:41 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	screento_cr(int x, t_win_info w)
{
	double tmp;

	tmp = (double)x / SIZE;
	return ((tmp * ((w.x2 - w.x1))) + w.x1);
}

double	screento_ci(int y, t_win_info w)
{
	double tmp;

	tmp = (double)y / SIZE;
	return ((tmp * ((w.y2 - w.y1))) + w.y1);
}
