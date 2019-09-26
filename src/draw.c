/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:11:54 by hdanylev          #+#    #+#             */
/*   Updated: 2019/03/18 13:11:56 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int start, int end, t_global *global)
{
	int		red;
	int		green;
	int		blue;

	if (start == end)
		return (start);
	red = get_light((start >> 16) & 0xFF, (end >> 16) & 0xFF, global->per);
	green = get_light((start >> 8) & 0xFF, (end >> 8) & 0xFF, global->per);
	blue = get_light(start & 0xFF, end & 0xFF, global->per);
	return ((red << 16) | (green << 8) | blue);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

void	percentage(t_global *global, int xcurrent, int ycurrent)
{
	if (global->dr.steep)
		global->per = percent(global->dr.x0, global->dr.x1, xcurrent);
	else
		global->per = percent(global->dr.y0, global->dr.y1, ycurrent);
}

int		draw(t_global *global, t_dot **dot, int j, int i)
{
	while (++j < global->rows)
	{
		i = -1;
		while (++i < global->cols)
		{
			set_dot0(dot, i, j, global);
			if (j != global->rows - 1 && check_coord1(global, i, j))
			{
				set_dot1(dot, i, j + 1, global);
				drawline(global);
			}
			if (i != global->cols - 1 && check_coord2(global, i, j))
			{
				set_dot1(dot, i + 1, j, global);
				drawline(global);
			}
		}
	}
	mlx_hook(global->win->win, 2, 1L << 17, hook, global);
	mlx_put_image_to_window(global->win->mlx, global->win->win,
										global->win->img, 0, 0);
	mlx_loop(global->win->mlx);
	return (0);
}
