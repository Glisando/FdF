/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:42 by hdanylev          #+#    #+#             */
/*   Updated: 2019/03/14 15:03:44 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

int		ft_arraylen(char **mass)
{
	int len;

	len = 0;
	while (mass[len])
		len++;
	return (len);
}

void	ft_free_2array(char **mass)
{
	int i;

	i = 0;
	while (mass[i])
	{
		ft_strdel(&mass[i]);
		i++;
	}
	free(mass);
}

void	ft_rotate_matrix(t_global *global)
{
	double	a;
	double	b;
	double	c;

	a = global->a;
	b = global->b;
	c = global->c;
	global->t[0][0] = 0.5 * (cos(b + c) + cos(b - c));
	global->t[0][1] = 0.5 * (sin(b - c) - sin(b + c));
	global->t[0][2] = sin(b);
	global->t[1][0] = 0.25 * (cos(a - b + c) - cos(a + b + c) - cos(a + b - c)
		+ cos(a - b - c) + 2 * sin(a + c) - 2 * sin(a - c));
	global->t[1][1] = 0.25 * (2 * cos(a + c) + 2 * cos(a - c) + sin(a + b + c)
		- sin(-a + b + c) - sin(a - b + c) - sin(a + b - c));
	global->t[1][2] = 0.5 * (-sin(a + b) - sin(a - b));
	global->t[2][0] = 0.25 * (-2 * cos(a + c) + 2 * cos(a - c) - sin(a + b + c)
		- sin(-a + b + c) - sin(a + b - c) - sin(-a + b - c));
	global->t[2][1] = 0.25 * (-cos(a + b + c) - cos(-a + b + c) + cos(a - b + c)
		+ cos(a + b - c) + 2 * sin(a + c) + 2 * sin(a - c));
	global->t[2][2] = 0.5 * (cos(a + b) + cos(a - b));
}
