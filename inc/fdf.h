/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:41:03 by hdanylev          #+#    #+#             */
/*   Updated: 2019/03/12 16:41:04 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"
#include "../libft/printf.h"

typedef struct  	s_coords
{
    unsigned int	x;
    unsigned int	y;
    int				z;
	unsigned int	cols;
    unsigned int	color;
    struct s_coords	*next;
}               	t_coords;

typedef struct  	s_dot
{
    double	x;
    double	y;
	double	z;
	unsigned int	cols;
    unsigned int	color;
}               	t_dot;

typedef struct		s_global
{
	unsigned int	rows;
	double			a;
	double			b;
	double			c;
	double			t[3][3];
	double			scale;
	t_coords		*coord;
	t_dot			**dot;
}					t_global;


/* ------- Utils ------- */

void	ft_free_2array(char **mass);
void	ft_rotate_matrix(t_global *global);
int		ft_arraylen(char **mass);

t_global	*init_global_struct(t_coords *coord, unsigned int rows);
int		calculate_coords(t_global *global, unsigned int cols);

#endif