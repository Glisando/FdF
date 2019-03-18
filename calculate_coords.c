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

t_dot		ft_new_dot(t_global *global,
			t_coords *lst, t_dot dot)
{
	dot.x = global->t[0][0] * lst->x + global->t[1][0] * lst->y + global->t[2][0] * lst->z * global->scale;
	dot.y = global->t[0][1] * lst->x + global->t[1][1] * lst->y + global->t[2][1] * lst->z * global->scale;
	dot.z = global->t[0][2] * lst->x + global->t[1][2] * lst->y + global->t[2][2] * lst->z * global->scale;
	dot.color = lst->color;
	return (dot);
}

int			calculate_coords(t_global *global)
{
	int			i;
	int			j;
	t_dot		*dot;
	t_coords	*lst;

	j = -1;
	lst = global->coord;
	ft_rotate_matrix(global);
	while (++j < global->rows)
	{
		i = -1;
		dot = (t_dot*)malloc(sizeof(t_dot) * global->cols);
		printf("cols: %u\n", global->cols);
		while (++i < global->cols)
		{
			dot[i] = ft_new_dot(global, lst, dot[i]);
			lst = lst->next;
		}
		global->dot[j] = dot;
	}
	// draw(global);
	return (1);
}
