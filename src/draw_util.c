/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:42 by hdanylev          #+#    #+#             */
/*   Updated: 2019/03/14 15:03:44 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot(double x, double y, double c, t_global *global)
{
	int i;
	int	start_c;
	int	cur_c;

	start_c = 0;
	cur_c = 0;
	if ((x < global->width && x > 0) && (y < global->height && y > 0))
	{
		i = (x * global->bpp / 8) + (y * global->size_line);
		start_c = global->dot[global->ycur][global->xcur].def_c;
		cur_c = global->dot[global->ycur][global->xcur].color;
		// if (global->dot[global->ycur][global->xcur].z > 0)
			start_c = get_color(start_c, cur_c, global->end_c , global);

		global->img_data[i] = (start_c & 255) * c;
		global->img_data[++i] = ((start_c >> 8) & 255) * c;
		global->img_data[++i] = ((start_c >> 16) & 255) * c;
		global->img_data[++i] = 0;
	}
}

int		ipart(double x)
{
	return (floor(x));
}

double	round(double x)
{
	return (ipart(x + 0.5));
}

double	fpart(double x)
{
	return (x - floor(x));
}

double	rfpart(double x)
{
	return (1 - fpart(x));
}
