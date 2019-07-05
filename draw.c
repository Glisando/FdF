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

#include "inc/fdf.h"

void	drawLine(double x0, double y0, double x1, double y1, t_global *global)
{
	bool steep;

	steep = fabs(y1 - y0) > fabs(x1 - x0);

	if (steep)
	{
		ft_swap(&x0, &y0);
		ft_swap(&x1, &y1);
	}

	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}

	double dx = x1 - x0;
	double dy = y1 - y0;
	double gradient = dy / dx;
	if (dx == 0.0)
	{
		gradient = 1.0;
	}

	// handle first endpoint
	double xend = round(x0);
	double yend = y0 + gradient * (xend - x0);
	double xgap = rfpart(x0 + 0.5);
	int xpxl1 = xend; // this will be used in the main loop
	int ypxl1 = ipart(yend);
	if (steep)
	{
		plot(ypxl1, xpxl1, rfpart(yend) * xgap, global);
		plot(ypxl1+1, xpxl1, fpart(yend) * xgap, global);
	}
	else
	{
		plot(xpxl1, ypxl1, rfpart(yend) * xgap, global);
		plot(xpxl1, ypxl1 + 1, fpart(yend) * xgap, global);
	}

	double intery = yend + gradient; // first y-intersection for the main loop

	// handle second endpoint
	xend = round(x1);
	yend = y1 + gradient * (xend - x1);
	xgap = fpart(x1 + 0.5);
	int xpxl2 = xend; //this will be used in the main loop
	int ypxl2 = ipart(yend);
	if (steep)
	{
		plot(ypxl2, xpxl2, rfpart(yend) * xgap, global);
		plot(ypxl2 + 1, xpxl2, fpart(yend) * xgap, global);
	}
	else
	{
		plot(xpxl2, ypxl2,  rfpart(yend) * xgap, global);
		plot(xpxl2, ypxl2 + 1, fpart(yend) * xgap, global);
	}

	// main loop
	if (steep)
	{
		for (int x = xpxl1 + 1; x < xpxl2 - 1; x++)
		{
			plot(ipart(intery), x, rfpart(intery), global);
			plot(ipart(intery) + 1, x, fpart(intery), global);
			intery = intery + gradient;
		}
	}
	else
	{
		for (int x = xpxl1 + 1; x < xpxl2 - 1; x++)
		{
			plot(x, ipart(intery), rfpart(intery), global);
			plot(x, ipart(intery) + 1, fpart(intery), global);
			intery = intery + gradient;
		}
	}
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

int		draw(t_global *global)
{
	int		i;
	int		j;
	int		x;
	t_dot	**dot;

	dot = global->dot;
	j = 0;
	x = 0;
	while (j < global->rows)
	{
		i = 0;
		while (i < global->cols)
		{
			global->xcur = i;
			global->ycur = j;
			if (j != global->rows - 1 && check_coord1(global, i, j))
				drawLine(dot[j][i].x, dot[j][i].y, dot[j + 1][i].x, dot[j + 1][i].y, global);
			if (i != global->cols - 1 && check_coord2(global, i, j))
				drawLine(dot[j][i].x, dot[j][i].y, dot[j][i + 1].x, dot[j][i + 1].y, global);
			i++;
		}
		j++;
	}
	mlx_hook(global->win->win, 2, 1L << 17, hook, global);
	mlx_put_image_to_window(global->win->mlx, global->win->win, global->win->img,
																		0, 0);
	mlx_loop(global->win->mlx);
	return (0);
}
