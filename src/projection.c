/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:24:03 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/18 16:35:49 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

t_mlx	*rotation_matrix_x_y_z(t_mlx *d)
{
	double	a;
	double	b;
	double	c;

	a = d->a;
	b = d->b;
	c = d->c;
	d->t[0][0] = 0.5 * (cos(b + c) + cos(b - c));
	d->t[0][1] = 0.5 * (sin(b - c) - sin(b + c));
	d->t[0][2] = sin(b);
	d->t[1][0] = 0.25 * (cos(a - b + c) - cos(a + b + c) - cos(a + b - c)
		+ cos(a - b - c) + 2 * sin(a + c) - 2 * sin(a - c));
	d->t[1][1] = 0.25 * (2 * cos(a + c) + 2 * cos(a - c) + sin(a + b + c)
		- sin(-a + b + c) - sin(a - b + c) - sin(a + b - c));
	d->t[1][2] = 0.5 * (-sin(a + b) - sin(a - b));
	d->t[2][0] = 0.25 * (-2 * cos(a + c) + 2 * cos(a - c) - sin(a + b + c)
		- sin(-a + b + c) - sin(a + b - c) - sin(-a + b - c));
	d->t[2][1] = 0.25 * (-cos(a + b + c) - cos(-a + b + c) + cos(a - b + c)
		+ cos(a + b - c) + 2 * sin(a + c) + 2 * sin(a - c));
	d->t[2][2] = 0.5 * (cos(a + b) + cos(a - b));
	return (d);
}

void	projection(t_dot **m, t_mlx *d, t_win *wi)
{
	double	x;
	double	y;
	double	z;
	int		i;
	int		j;

	i = -1;
	rotation_matrix_x_y_z(d);
	while (++i < d->line)
	{
		j = -1;
		while (++j < d->row)
		{
			x = d->t[0][0] * m[i][j].x + d->t[1][0] * m[i][j].y
			+ d->t[2][0] * m[i][j].z * d->scale;
			y = d->t[0][1] * m[i][j].x + d->t[1][1] * m[i][j].y
			+ d->t[2][1] * m[i][j].z * d->scale;
			z = d->t[0][2] * m[i][j].x + d->t[1][2] * m[i][j].y
			+ d->t[2][2] * m[i][j].z * d->scale;
			m[i][j].x = x;
			m[i][j].y = y;
			m[i][j].z = z;
		}
	}
	image(m, d, wi);
}
