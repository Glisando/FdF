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
	dot.x = global->t[0][0] * lst->x + global->t[1][0] *
		lst->y + global->t[2][0] * lst->z * global->scale;
	dot.y = global->t[0][1] * lst->x + global->t[1][1] *
		lst->y + global->t[2][1] * lst->z * global->scale;
	dot.z = global->t[0][2] * lst->x + global->t[1][2] *
		lst->y + global->t[2][2] * lst->z * global->scale;
	dot.color = lst->color;
	dot.cols = lst->cols;
	return (dot);
}

int			calculate_coords(t_global *global, unsigned int cols)
{
	unsigned int	i;
	unsigned int	j;
	t_dot			*dot;
	t_coords		*lst;

	j = -1;
	lst = global->coord;
	ft_rotate_matrix(global);
	while (++j < global->rows)
	{
		i = -1;
		cols = lst->cols;
		dot = (t_dot*)malloc(sizeof(t_dot) * cols);
		printf("cols: %u\n", lst->cols);
		while (++i < cols)
		{
			dot[i] = ft_new_dot(global, lst, dot[i]);
			lst = lst->next;
		}
		global->dot[j] = dot;
	}
	return (1);
}

t_global	*init_global_struct(t_coords *coord, unsigned int rows)
{
	t_global *global;

	global = (t_global*)malloc(sizeof(t_global));
	global->a = 20;
	global->b = 20;
	global->c = 20;
	global->scale = 15;
	global->rows = rows;
	global->coord = coord;
	global->dot = (t_dot**)malloc(sizeof(t_dot*) * rows);
	printf("rows: %u\n", rows);
	return (global);
}
