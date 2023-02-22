/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:11 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/06 13:25:21 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	skip(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	i++;
	if (str[i] == '-')
		*sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		sign;
	double	div;

	nb = 0;
	div = 0.1;
	sign = 1;
	i = skip(str, &sign);
	while (str[i] && str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	return (nb * sign);
}
