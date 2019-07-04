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

#include "inc/fdf.h"

int			calculate_coords(t_global *global)
{
	int			i;
	int			j;
	t_coords	*lst;

	j = -1;
	lst = global->coord;
	ft_rotate_matrix(global);
	while (++j < global->rows)
	{
		i = -1;
		while (++i < global->cols)
		{
			global->dot[j][i].x = (global->t[0][0] * lst->x + global->t[1][0] * lst->y - global->t[2][0] * lst->z) * global->scale;
			global->dot[j][i].y = (global->t[0][1] * lst->x + global->t[1][1] * lst->y - global->t[2][1] * lst->z) * global->scale;
			global->dot[j][i].z = (global->t[0][2] * lst->x + global->t[1][2] * lst->y + global->t[2][2] * lst->z) * global->scale;
			global->dot[j][i].color = lst->color;
			lst = lst->next;
		}
	}
	draw(global);
	return (1);
}
