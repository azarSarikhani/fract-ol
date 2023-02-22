/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/16 14:51:31 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *fractol, double zoom)
{
	double	center_re;
	double	center_im;

	center_re = fractol->min_re - fractol->max_re;
	center_im = fractol->max_im - fractol->min_im;
	fractol->max_re = fractol->max_re + (center_re - zoom * center_re) / 2;
	fractol->min_re = fractol->max_re + zoom * center_re;
	fractol->min_im = fractol->min_im + (center_im - zoom * center_im) / 2;
	fractol->max_im = fractol->min_im + zoom * center_im;
}

static void	move(t_fractol *fractol, double distance, char direction)
{
	double	center_re;
	double	center_im;

	center_re = fractol->max_re - fractol->min_re;
	center_im = fractol->max_im - fractol->min_im;
	if (direction == 'R')
	{
		fractol->min_re += center_re * distance;
		fractol->max_re += center_re * distance;
	}
	else if (direction == 'L')
	{
		fractol->min_re -= center_re * distance;
		fractol->max_re -= center_re * distance;
	}
	else if (direction == 'D')
	{
		fractol->min_im -= center_im * distance;
		fractol->max_im -= center_im * distance;
	}
	else if (direction == 'U')
	{
		fractol->min_im += center_im * distance;
		fractol->max_im += center_im * distance;
	}
}

int	mouse_event(int keycode, int x, int y, t_fractol *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else if (keycode == MOUSE_BTN)
	{
		if (mlx->set == JULIA)
			julia_shift(x, y, mlx);
	}
	else
		return (0);
	render(mlx);
	return (0);
}

static int	key_event_extend(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ONE && mlx->set != MANDELBROT)
		mlx->set = MANDELBROT;
	else if (keycode == KEY_TWO && mlx->set != JULIA)
		mlx->set = JULIA;
	else
		return (1);
	layout(mlx);
	render(mlx);
	return (0);
}

int	key_event(int keycode, t_fractol *mlx)
{
	if (keycode == KEY_ESC)
	{
		end_fractol(mlx);
		return (0);
	}
	else if (keycode == KEY_PLUS)
		zoom(mlx, 0.5);
	else if (keycode == KEY_MINUS)
		zoom(mlx, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(mlx, 0.2, 'U');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(mlx, 0.2, 'D');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(mlx, 0.2, 'L');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(mlx, 0.2, 'R');
	else if (!key_event_extend(keycode, mlx))
		return (1);
	else
		return (1);
	render(mlx);
	return (0);
}
