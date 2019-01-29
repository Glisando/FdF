/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 15:42:04 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/18 12:29:22 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_win	*ft_if(t_win *wi, t_mlx *d)
{
	d->length++;
	while (d->length--)
	{
		mlx_pixel_put(wi->mlx, wi->win, d->tmpx, d->tmpy, 8190976);
		d->tmpx += d->dx;
		d->ddx += 2 * d->lengthy;
		if (d->ddx > 0)
		{
			d->ddx -= 2 * d->lengthx;
			d->tmpy += d->dy;
		}
	}
	return (wi);
}

t_win	*ft_else(t_win *wi, t_mlx *d)
{
	d->length++;
	while (d->length--)
	{
		mlx_pixel_put(wi->mlx, wi->win, d->tmpx, d->tmpy, 8190976);
		d->tmpy += d->dy;
		d->ddy += 2 * d->lengthx;
		if (d->ddy > 0)
		{
			d->ddy -= 2 * d->lengthy;
			d->tmpx += d->dx;
		}
	}
	return (wi);
}

t_win	*drawline(t_win *wi, t_mlx *d)
{
	d->dx = (d->x2 - d->x1 >= 0 ? 1 : -1);
	d->dy = (d->y2 - d->y1 >= 0 ? 1 : -1);
	d->lengthx = abs(d->x2 - d->x1);
	d->lengthy = abs(d->y2 - d->y1);
	d->length = fmax(d->lengthx, d->lengthy);
	d->ddy = -d->lengthy;
	d->tmpx = d->x1;
	d->tmpy = d->y1;
	d->ddx = -d->lengthx;
	if (d->length == 0)
		mlx_pixel_put(wi->mlx, wi->win, d->x1, d->y1, 8190976);
	if (d->lengthy <= d->lengthx)
	{
		wi = ft_if(wi, d);
	}
	else
	{
		wi = ft_else(wi, d);
	}
	return (wi);
}

t_win	*rows(t_dot **m, t_mlx *d, t_win *wi)
{
	double	x;
	double	y;
	int		j;
	int		i;

	y = 200;
	i = 0;
	while (i + 1 < d->line)
	{
		x = 150;
		j = 0;
		while (j < d->row)
		{
			d = set_dots1(d, m[i][j].x + x, m[i][j].y + y);
			d = set_dots2(d, m[i + 1][j].x + x, m[i + 1][j].y + y + d->scale);
			drawline(wi, d);
			x += d->scale;
			j++;
		}
		y += d->scale;
		i++;
	}
	return (wi);
}

void	image(t_dot **m, t_mlx *d, t_win *wi)
{
	double	x;
	double	y;
	int		j;
	int		i;

	wi->mlx = mlx_init();
	wi->win = mlx_new_window(wi->mlx, 1000, 1000, "mlx 42");
	y = 200;
	i = -1;
	while (++i < d->line)
	{
		x = 150;
		j = -1;
		while (++j + 1 < d->row)
		{
			d = set_dots1(d, m[i][j].x + x, m[i][j].y + y);
			d = set_dots2(d, m[i][j + 1].x + x + d->scale, m[i][j + 1].y + y);
			drawline(wi, d);
			x += d->scale;
		}
		y += d->scale;
	}
	wi = rows(m, d, wi);
	mlx_hook(wi->win, 17, 1L << 17, exit_x, wi);
	mlx_loop(wi->mlx);
}
