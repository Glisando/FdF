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

	i = (x * global->bpp / 8) + (y * global->size_line);
	global->img_data[i] = (global->dot[global->ycur][global->xcur].color & 255) * c;
	global->img_data[++i] = ((global->dot[global->ycur][global->xcur].color >> 8) & 255) * c;
	global->img_data[++i] = ((global->dot[global->ycur][global->xcur].color >> 16) & 255) * c;
	global->img_data[++i] = 0;
}

int     ipart(double x)
{
    return floor(x);
}

double  round(double x)
{
    return ipart(x + 0.5);
}

double  fpart(double x)
{
    return x - floor(x);
}

double  rfpart(double x)
{
    return 1 - fpart(x);
}