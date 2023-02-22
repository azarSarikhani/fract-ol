/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/20 11:30:12 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_message(t_fractol *fractol)
{
	ft_putendl_fd("Choose one of the fractals below: ", 1);
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("\nmandelbrot", 1);
	ft_putendl_fd("\njulia", 1);
	ft_putendl_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putendl_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	clean_exit(EXIT_FAILURE, fractol);
}

int	message(char *str1, char *str2, int errno)
{
	ft_putstr_fd("Fractol: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putendl_fd(str2, 2);
	return (errno);
}

void	nav_help(void)
{
	ft_putendl_fd("\n+===============  Navigation  ======================+", 1);
	ft_putendl_fd("WASD or arrow keys\tmove view.", 1);
	ft_putendl_fd("+/- or scroll wheel\tzoom in and out.", 1);
	ft_putendl_fd("Left click\t\tshift Julia set [Julia only].", 1);
	ft_putendl_fd("1, 2 \t\t\tswitch fractals.", 1);
	ft_putendl_fd("ESC or close window\tquit fract'ol.", 1);
	ft_putendl_fd("+====================================================+\n", 1);
}
