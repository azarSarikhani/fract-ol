/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/16 14:14:52 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_shift(int x, int y, t_fractol *fractol)
{
	fractol->k_re = fractol->min_re + (double)x
		* (fractol->max_re - fractol->min_re) / (WIDTH - 1);
	fractol->k_im = fractol->max_im + (double)y
		* (fractol->min_im - fractol->max_im) / (HEIGHT - 1);
	render(fractol);
	return (0);
}

int	julia(t_fractol *fractol, double z_re, double z_im)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < MAX_ITERATION)
	{
		if ((z_re * z_re + z_im * z_im) > 4.0)
			break ;
		temp = 2 * z_re * z_im + fractol->k_im;
		z_re = z_re * z_re - z_im * z_im + fractol->k_re;
		z_im = temp;
		iter++;
	}
	return (iter);
}
