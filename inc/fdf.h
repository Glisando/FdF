/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:37:17 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/18 13:00:37 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libftprintf/inc/printf.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# define ROUNDF(x) FLOOR((x) + 0.5(f))

typedef struct	s_win
{
	void	*mlx;
	void	*win;

}				t_win;

typedef struct	s_dot
{
	double	x;
	double	y;
	double	z;
}				t_dot;

typedef struct	s_mlx
{
	int		row;
	int		line;
	int		size;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		lengthx;
	int		lengthy;
	int		length;
	int		tmpx;
	int		tmpy;
	int		ddx;
	int		ddy;
	double	scale;
	double	a;
	double	b;
	double	c;
	double	t[3][3];

}				t_mlx;

t_mlx			*set_dots2(t_mlx *d, double x2, double y2);
t_mlx			*set_dots1(t_mlx *d, double x1, double y1);
t_mlx			*rotation_matrix_x_y_z(t_mlx *d);
void			structure(int fd, int size, int row);
void			ft_free_mass(char **mass);
int				exit_x(void *par);
void			image(t_dot **m, t_mlx *d, t_win *wi);
void			projection(t_dot **m, t_mlx *d, t_win *wi);

#endif
