/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:57:09 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/18 17:22:17 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_data(t_dot **m, t_mlx *d)
{
	t_win *wi;

	wi = (t_win*)malloc(sizeof(t_win));
	projection(m, d, wi);
}

void	ft_set_coord(char *line, int fd, t_mlx *d, t_dot **m)
{
	char	**mass;
	int		x;
	int		i;
	int		j;

	i = 0;
	while ((get_next_line(fd, &line)))
	{
		mass = ft_strsplit(line, ' ');
		x = 0;
		j = 0;
		while (j < d->row)
		{
			m[i][j].x = (double)j;
			m[i][j].y = (double)i;
			m[i][j].z = ft_atoi(&mass[x][0]);
			x++;
			j++;
		}
		ft_free_mass(mass);
		ft_strdel(&line);
		i++;
	}
	close(fd);
	ft_data(m, d);
}

void	structure(int fd, int size, int row)
{
	int		i;
	t_dot	**m;
	t_mlx	*d;

	d = (t_mlx*)malloc(sizeof(t_mlx));
	d->size = size;
	d->row = row;
	d->line = size / row;
	d->scale = 15;
	d->a = -50;
	d->b = -20;
	d->c = 20;
	m = (t_dot**)malloc(sizeof(t_dot*) * d->line);
	i = 0;
	while (i < d->line)
	{
		m[i] = (t_dot*)malloc(sizeof(t_dot) * row);
		i++;
	}
	ft_set_coord(NULL, fd, d, m);
}
