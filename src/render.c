/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/20 11:28:34 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	fractol_check(t_fractol *fractol, double c_re, double c_im)
{
	int	iter;

	iter = 0;
	if (fractol->set == MANDELBROT)
		iter = mandelbrot(c_re, c_im);
	if (fractol->set == JULIA)
		iter = julia(fractol, c_re, c_im);
	return (iter);
}

static int	calculate_color(int iter)
{
	int	color;

	if (iter < 2)
		color = 0xf0f8ff;
	else if (iter < 3)
		color = 0xd0f2c7;
	else if (iter < 4)
		color = 0x00cccc;
	else if (iter < 6)
		color = 0x009966;
	else if (iter < 8)
		color = 0x006600;
	else if (iter < 16)
		color = 0x006699;
	else if (iter < 25)
		color = 0x00cccc;
	else if (iter < 35)
		color = 0xae6cae;
	else if (iter < 48)
		color = 0x660066;
	else if (iter < 64)
		color = 0x660000;
	else
		color = 0x000000;
	return (color);
}

static void	pixel_color(t_fractol *fractol, int x, int y, int iter)
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*dst;
	int		color;

	fractol->buf = mlx_get_data_addr(fractol->img,
			&bits_per_pixel, &line_length, &endian);
	dst = fractol->buf + (y * line_length + x * (bits_per_pixel / 8));
	color = calculate_color(iter);
	*(unsigned int *)dst = color;
}

void	render(t_fractol *fractol)
{
	int		x;
	int		y;
	double	c_re;
	double	c_im;
	int		iter;

	mlx_clear_window(fractol->mlx, fractol->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		c_im = fractol->max_im - (double)y
			* (fractol->max_im - fractol->min_im) / (HEIGHT -1);
		while (++x < WIDTH)
		{
			c_re = fractol->min_re + (double)x
				* (fractol->max_re - fractol->min_re) / (WIDTH -1);
			iter = fractol_check(fractol, c_re, c_im);
			pixel_color(fractol, x, y, iter);
		}
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
}
