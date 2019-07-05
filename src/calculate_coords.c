/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:33:47 by hdanylev          #+#    #+#             */
/*   Updated: 2019/03/14 17:33:48 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	math_for_translating(t_global *global, t_coords *lst, int i, int j)
{
	int x;
	int y;

	x = lst->x - (global->cols / 2);
	y = lst->y - (global->rows / 2);
	global->dot[j][i].x = (global->t[0][0] * x + global->t[1][0]
		* y - global->t[2][0] * lst->z) * global->scale;
	global->dot[j][i].y = (global->t[0][1] * x + global->t[1][1]
		* y - global->t[2][1] * lst->z) * global->scale;
	global->dot[j][i].z = (global->t[0][2] * x + global->t[1][2]
		* y + global->t[2][2] * lst->z) * global->scale;
	global->dot[j][i].color = lst->color;
	global->dot[j][i].def_c = lst->color;
	global->dot[j][i].x += global->width / 2;
	global->dot[j][i].y += global->height / 2;
}

void	check_params(t_global *global)
{
	int w;
	int h;

	w = global->width;
	h = global->height;
	global->a = fabs(global->a * 57.2958) > 360 ? 0 : global->a;
	global->b = fabs(global->b * 57.2958) > 360 ? 0 : global->b;
	global->c = fabs(global->c * 57.2958) > 360 ? 0 : global->c;
	global->scale -= global->scale > w / global->cols * 5 ? 0.6 : 0;
	global->scale -= global->scale > w / global->rows * 5 ? 0.6 : 0;
	global->scale += global->scale < 1 ? 0.6 : 0;
}

int		calculate_coords(t_global *global)
{
	int			i;
	int			j;
	t_coords	*lst;

	j = -1;
	lst = global->coord;
	check_params(global);
	ft_rotate_matrix(global);
	while (++j < global->rows)
	{
		i = -1;
		while (++i < global->cols)
		{
			math_for_translating(global, lst, i, j);
			lst = lst->next;
		}
	}
	draw(global, global->dot, -1, -1);
	return (1);
}
