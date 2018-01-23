/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 13:35:01 by fde-souz          #+#    #+#             */
/*   Updated: 2018/01/22 18:19:32 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# define SIZE 800.00

typedef struct		s_palette
{
	int				nb;
	int				pal[32];
}					t_palette;

typedef struct		s_struc_data_point
{
	int				x;
	int				y;
	int				color;
}					t_struc_data_point;

typedef struct		s_fract
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			tmpr;
	double			tmpi;
}					t_fract;

typedef struct		s_win_info
{
	void				*mlx;
	void				*win;
	void				*ima;
	char				*str;
	int					bpp;
	int					sl;
	int					e;
	int					imax;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	int					fractal;
	t_palette			pal;
	int					m_x;
	int					m_y;
	int					togle;
}					t_win_info;

void				put_pixel_image(int x, int y, int color,
	t_win_info *wininf);
double				screento_cr(int x, t_win_info w);
double				screento_ci(int y, t_win_info w);
void				mandelbrot(t_win_info *w);
void				set_param_mandelbrot(t_win_info *w);
void				display_fract(t_win_info *w);
void				julia(t_win_info *w);
void				set_param_julia(t_win_info *w);
int					my_key_funct(int key, void *param);
int					mouse_hook(int button, int x, int y, void *param);
t_palette			set_pal(int key);
int					my_mouse_move(int x, int y, void *param);
void				burning_ship(t_win_info *w);
void				set_param_burning_ship(t_win_info *w);

#endif
