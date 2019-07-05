/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:54:50 by hdanylev          #+#    #+#             */
/*   Updated: 2019/07/05 19:54:52 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawline4(t_global *global, t_dl dr)
{
	int x;

	if (dr.steep)
	{
		x = dr.xpxl1 + 1;
		while (x < dr.xpxl2 - 1)
		{
			percentage(global, dr, ipart(dr.intery), x);
			plot(ipart(dr.intery), x, rfpart(dr.intery), global);
			percentage(global, dr, ipart(dr.intery) + 1, x);
			plot(ipart(dr.intery) + 1, x, fpart(dr.intery), global);
			dr.intery = dr.intery + dr.gradient;
			x++;
		}
	}
	else
	{
		x = dr.xpxl1 + 1;
		while (x < dr.xpxl2 - 1)
		{
			percentage(global, dr, x, ipart(dr.intery));
			plot(x, ipart(dr.intery), rfpart(dr.intery), global);
			percentage(global, dr, x, ipart(dr.intery) + 1);
			plot(x, ipart(dr.intery) + 1, fpart(dr.intery), global);
			dr.intery = dr.intery + dr.gradient;
			x++;
		}
	}
}

void	drawline3(t_global *global, t_dl dr)
{
	dr.intery = dr.yend + dr.gradient;
	dr.xend = round(dr.x1);
	dr.yend = dr.y1 + dr.gradient * (dr.xend - dr.x1);
	dr.xgap = fpart(dr.x1 + 0.5);
	dr.xpxl2 = dr.xend;
	dr.ypxl2 = ipart(dr.yend);
	if (dr.steep)
	{
		percentage(global, dr, dr.ypxl2, dr.xpxl2);
		plot(dr.ypxl2, dr.xpxl2, rfpart(dr.yend) * dr.xgap, global);
		percentage(global, dr, dr.ypxl2 + 2, dr.xpxl2);
		plot(dr.ypxl2 + 1, dr.xpxl2, fpart(dr.yend) * dr.xgap, global);
	}
	else
	{
		plot(dr.xpxl2, dr.ypxl2, rfpart(dr.yend) * dr.xgap, global);
		plot(dr.xpxl2, dr.ypxl2 + 1, fpart(dr.yend) * dr.xgap, global);
	}
	drawline4(global, dr);
}

void	drawline2(t_global *global, t_dl dr)
{
	dr.xend = round(dr.x0);
	dr.yend = dr.y0 + dr.gradient * (dr.xend - dr.x0);
	dr.xgap = rfpart(dr.x0 + 0.5);
	dr.xpxl1 = dr.xend;
	dr.ypxl1 = ipart(dr.yend);
	if (dr.steep)
	{
		percentage(global, dr, dr.ypxl1, dr.xpxl1);
		plot(dr.ypxl1, dr.xpxl1, rfpart(dr.yend) * dr.xgap, global);
		percentage(global, dr, dr.ypxl1 + 1, dr.xpxl1);
		plot(dr.ypxl1 + 1, dr.xpxl1, fpart(dr.yend) * dr.xgap, global);
	}
	else
	{
		percentage(global, dr, dr.xpxl1, dr.ypxl1);
		plot(dr.xpxl1, dr.ypxl1, rfpart(dr.yend) * dr.xgap, global);
		percentage(global, dr, dr.xpxl1, dr.ypxl1 + 1);
		plot(dr.xpxl1, dr.ypxl1 + 1, fpart(dr.yend) * dr.xgap, global);
	}
	drawline3(global, dr);
}

void	drawline(t_global *global)
{
	t_dl dr;

	dr.x0 = global->x0;
	dr.y0 = global->y0;
	dr.x1 = global->x1;
	dr.y1 = global->y1;
	dr.steep = fabs(dr.y1 - dr.y0) > fabs(dr.x1 - dr.x0);
	if (dr.steep)
	{
		ft_swap(&dr.x0, &dr.y0);
		ft_swap(&dr.x1, &dr.y1);
	}
	if (dr.x0 > dr.x1)
	{
		ft_swap(&dr.x0, &dr.x1);
		ft_swap(&dr.y0, &dr.y1);
	}
	dr.dx = dr.x1 - dr.x0;
	dr.dy = dr.y1 - dr.y0;
	dr.gradient = dr.dy / dr.dx;
	if (dr.dx == 0.0)
		dr.gradient = 1.0;
	drawline2(global, dr);
}
