/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:20:33 by hdanylev          #+#    #+#             */
/*   Updated: 2019/07/05 13:20:34 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(double *a, double *b)
{
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

bool	check_coord1(t_global *global, int i, int j)
{
	int x;
	int y;

	x = global->dot[j][i].x;
	y = global->dot[j][i].y;
	if ((x > global->width || x < 0) || (y > global->height || y < 0))
		return (false);
	x = global->dot[j + 1][i].x;
	y = global->dot[j + 1][i].y;
	if ((x > global->width || x < 0) || (y > global->height || y < 0))
		return (false);
	return (true);
}

bool	check_coord2(t_global *global, int i, int j)
{
	int x;
	int y;

	x = global->dot[j][i].x;
	y = global->dot[j][i].y;
	if ((x > global->width || x < 0) || (y > global->height || y < 0))
		return (false);
	x = global->dot[j][i + 1].x;
	y = global->dot[j][i + 1].y;
	if ((x > global->width || x < 0) || (y > global->height || y < 0))
		return (false);
	return (true);
}

void	set_dot0(t_dot **dot, int i, int j, t_global *global)
{
	global->x0 = dot[j][i].x;
	global->y0 = dot[j][i].y;
	global->xcur = i;
	global->ycur = j;
}

void	set_dot1(t_dot **dot, int i, int j, t_global *global)
{
	global->x1 = dot[j][i].x;
	global->y1 = dot[j][i].y;
	global->xend = i;
	global->yend = j;
}
