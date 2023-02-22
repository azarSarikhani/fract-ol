/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/20 11:28:18 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>

# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATION 64

# define MANDELBROT 1
# define JULIA 2

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_ONE 83
# define KEY_TWO 84
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3
# define MOUSE_BTN 1
# define MOUSE_BTN_2 3

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		set;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	k_re;
	double	k_im;
}	t_fractol;

void	clean_init(t_fractol *fractol);
void	init(t_fractol *fractol);
void	clean_exit(int exit_code, t_fractol *fractol);
void	help_message(t_fractol *fractol);
int		message(char *str1, char *str2, int errno);
double	ft_atof(char *str);
void	render(t_fractol *fractol);
void	nav_help(void);
int		julia(t_fractol *fractol, double z_re, double z_im);
int		mandelbrot(double c_re, double c_im);
void	init_img(t_fractol *fractol);
int		mouse_event(int keycode, int x, int y, t_fractol *mlx);
int		julia_shift(int x, int y, t_fractol *fractol);
int		end_fractol(t_fractol *fractol);
int		key_event(int keycode, t_fractol *mlx);
void	layout(t_fractol *fractol);

#endif