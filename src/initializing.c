/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/16 14:49:18 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_init(t_fractol *fractol)
{
	fractol->mlx = NULL;
	fractol->win = NULL;
	fractol->img = NULL;
	fractol->buf = NULL;
	fractol->set = -1;
	fractol->min_re = 0;
	fractol->max_re = 0;
	fractol->min_im = 0;
	fractol->max_im = 0;
	fractol->k_re = 0;
	fractol->k_im = 0;
}

void	init_img(t_fractol *fractol)
{
	if (fractol->mlx && fractol->img)
		mlx_destroy_image(fractol->mlx, fractol->img);
	if (fractol->buf)
		fractol->buf = NULL;
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!(fractol->img))
		clean_exit(message("image creation error.", "", 1), fractol);
}

void	layout(t_fractol *fractol)
{
	if (fractol->set == JULIA)
	{
		fractol->min_re = -2.0;
		fractol->max_re = 2.0;
		fractol->min_im = -2.0;
		fractol->max_im = fractol->min_im + (fractol->max_re - fractol->min_re)
			* HEIGHT / WIDTH;
	}
	else
	{
		fractol->min_re = -2.0;
		fractol->max_re = 1.0;
		fractol->min_im = -1.2;
		fractol->max_im = fractol->min_im + (fractol->max_re - fractol->min_re)
			* HEIGHT / WIDTH;
	}
}

void	init(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		clean_exit(message("MLX: error connecting to mlx.", "", 1), fractol);
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	if (!fractol->win)
		clean_exit(message("MLX: error creating window.", "", 1), fractol);
	layout(fractol);
	init_img(fractol);
}
