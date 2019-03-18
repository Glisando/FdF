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
# define ROUNDF(x) FLOOR(x + 0.5f)

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "../libft/printf.h"

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_win;

typedef struct  	s_coords
{
    unsigned int	x;
    unsigned int	y;
    int				z;
    unsigned int	color;
    struct s_coords	*next;
}               	t_coords;

typedef struct  	s_dot
{
    double	x;
    double	y;
	double	z;
    unsigned int	color;
}               	t_dot;

typedef struct		s_global
{
	int				rows;
	int				cols;
	int				size;
	double			a;
	double			b;
	double			c;
	double			t[3][3];
	double			scale;
	t_coords		*coord;
	t_dot			**dot;
	t_win			*win;
}					t_global;


/* ------- Utils ------- */

void		ft_free_2array(char **mass);
void		ft_rotate_matrix(t_global *global);
int			ft_arraylen(char **mass);

t_global	*init_global_struct(t_coords *coord, int rows, int cols);
t_win		*init_win(int rows, int cols, int size, double scale);
int			calculate_coords(t_global *global);

#endif