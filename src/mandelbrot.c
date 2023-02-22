/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/20 11:28:26 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double c_re, double c_im)
{
	int		iter;
	double	z_re;
	double	z_im;
	double	temp;

	z_re = c_re;
	z_im = c_im;
	iter = 0;
	while (iter < MAX_ITERATION)
	{
		if ((z_re * z_re + z_im * z_im) > 4.0)
		{
			break ;
		}
		temp = 2 * z_re * z_im + c_im;
		z_re = z_re * z_re - z_im * z_im + c_re;
		z_im = temp;
		iter++;
	}
	return (iter);
}
