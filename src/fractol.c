/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/16 15:50:24 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	get_julia_start(t_fractol *fractol, int argc, char **argv)
{
	if (fractol->set != JULIA || argc == 2)
	{
		fractol->k_re = -0.766667;
		fractol->k_im = -0.090000;
		return ;
	}
	if (argc == 3 || !ft_strchr(argv[2], '.') || !ft_strchr(argv[3], '.'))
		help_message(fractol);
	fractol->k_re = ft_atof(argv[2]);
	fractol->k_im = ft_atof(argv[3]);
	if (fractol->k_re > 2.0 || fractol->k_re < -2.0
		|| fractol->k_im >= 2.0 || fractol->k_im <= -2.0)
		help_message(fractol);
}

static	void	get_set(t_fractol *fractol, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fractol->set = MANDELBROT;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		fractol->set = JULIA;
	else
		help_message(fractol);
}

static void	process_args(t_fractol *fractol, int argc, char **argv)
{
	get_set(fractol, argv);
	if (fractol->set != JULIA && argc > 3)
		help_message(fractol);
	else if (fractol->set == JULIA && argc > 5)
		help_message(fractol);
	get_julia_start(fractol, argc, argv);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	clean_init(&fractol);
	if (argc < 2)
		help_message(&fractol);
	process_args(&fractol, argc, argv);
	init(&fractol);
	render(&fractol);
	nav_help();
	mlx_hook(fractol.win, EVENT_CLOSE_BTN, 0, end_fractol, &fractol);
	mlx_key_hook(fractol.win, key_event, &fractol);
	mlx_mouse_hook(fractol.win, mouse_event, &fractol);
	mlx_loop(fractol.mlx);
}
