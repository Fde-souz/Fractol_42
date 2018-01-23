/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 11:37:09 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/23 13:09:52 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_palette	set_pal(int key)
{
	if (key == 20)
	{
		return ((t_palette){5, {0x61b3ff, 0x210a7f, 0x0588da, 0x0bcc31,
		0x21fd2b}});
	}
	else if (key == 18)
		return ((t_palette){16, {0x421e0f, 0x19071a, 0x090104, 0x09012f
			, 0x040449, 0x000764, 0x0c2c8a, 0x1852b1, 0x397dd1, 0x86b5e5
		, 0xddecf8, 0xf1e9bf, 0xf8c95f, 0xffaa00, 0xcc8000, 0x995700
		, 0x6a3403}});
	else if (key == 19)
		return ((t_palette){7, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}});
		return ((t_palette){2, {0x000000, 0xffffff}});
}
