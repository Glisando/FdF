/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw's_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:42 by hdanylev          #+#    #+#             */
/*   Updated: 2019/03/14 15:03:44 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

void    plot(double x, double y, double c, t_global *global)
{
    int i;

    // printf("%f | %f | %f | %i\n", x, y, c, global->size_line);
	if ((x < global->width && x > 0) && (y < global->height && y > 0))
	{
		i = (x * global->bpp / 8) + (y * global->size_line);
		global->img_data[i] = (global->dot[global->ycur][global->xcur].color & 255) * c;
		global->img_data[++i] = ((global->dot[global->ycur][global->xcur].color >> 8) & 255) * c;
		global->img_data[++i] = ((global->dot[global->ycur][global->xcur].color >> 16) & 255) * c;
		global->img_data[++i] = 0;
	}
}

// integer part of x
int     ipart(double x)
{
    return floor(x);
}

double  round(double x)
{
    return ipart(x + 0.5);
}

// fractional part of x
double  fpart(double x)
{
    return x - floor(x);
}

double  rfpart(double x)
{
    return 1 - fpart(x);
}