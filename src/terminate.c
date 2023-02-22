/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/25 11:50:23 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(int exit_code, t_fractol *fractol)
{
	if (!fractol)
		exit(exit_code);
	if (fractol->img && fractol->win && fractol->mlx)
	{
		mlx_destroy_image(fractol->mlx, fractol->img);
		mlx_destroy_window(fractol->mlx, fractol->win);
		fractol->mlx = NULL;
		fractol->win = NULL;
		fractol->buf = NULL;
		exit (exit_code);
	}
	else if (fractol->win && fractol->mlx)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		fractol->win = NULL;
		fractol->mlx = NULL;
		exit (exit_code);
	}
	else if (fractol->img && fractol->mlx)
	{
		mlx_destroy_image(fractol->mlx, fractol->img);
		fractol->img = NULL;
		exit (exit_code);
	}
	exit (exit_code);
}

int	end_fractol(t_fractol *fractol)
{
	clean_exit(0, fractol);
	return (0);
}
