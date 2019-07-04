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
void	new_image(t_global *glonal)
{
	mlx_destroy_image(glonal->win->mlx, glonal->win->img);
	glonal->win->img = mlx_new_image(glonal->win->mlx, 2000, 2000);
	calculate_coords(glonal);
}

int     hook(int key, t_global *params)
{
	bool	changed;

	changed = false;
    (key == 53) ? exit(1) : NULL;
	if (key == 124 && (changed = true))
		params->b += 1 * 0.0174533;
	else if (key == 123 && (changed = true))
		params->b -= 1 * 0.0174533;
	else if (key == 126 && (changed = true))
		params->a += 1 * 0.0174533;
	else if (key == 125 && (changed = true))
		params->a -= 1 * 0.0174533;
	else if (key == 115 && (changed = true))
		params->c -= 1 * 0.0174533;
	else if (key == 119 && (changed = true))
		params->c += 1 * 0.0174533;
	(changed == true) ? new_image(params) : NULL;
    return (0);
}