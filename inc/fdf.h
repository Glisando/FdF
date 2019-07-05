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
# include <stdbool.h>

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	unsigned int		*img;
}				t_win;

typedef struct	s_coords
{
    double			x;
    double			y;
    double			z;
    unsigned int	color;
    struct s_coords	*next;
}               	t_coords;

typedef struct  	s_dot
{
    double			x;
    double			y;
	double			z;
    unsigned int	color;
}               	t_dot;

typedef struct		s_global
{
	int				width;
	int				height;
	char			*img_data;
	int				rows;
	int				cols;
	int				bpp;
	int				size;
	int				endian;
	int				size_line;
	int				xcur;
	int				ycur;
	double			a;
	double			b;
	double			c;
	double			t[3][3];
	double			scale;
	t_coords		*coord;
	t_dot			**dot;
	t_win			*win;
}					t_global;

/* ------- Draw's utils ------- */
double		rfpart(double x);
double		fpart(double x);
double		round(double x);
int			ipart(double x);
void    	plot(double x, double y, double c, t_global * global);

/* ------- Utils ------- */
void		ft_free_2array(char **mass);
void		altitude_changing(t_coords *coord, double sign);
void		ft_rotate_matrix(t_global *global);
int			ft_arraylen(char **mass);
void		new_image(t_global *global);
void		ft_swap(double *a, double *b);

/* ------- Key Hook ------- */
int			hook(int key, t_global *params);
void		hook2(int key, t_global *params, bool *changed);
void		hook3(int key, t_global *params, bool *changed);

/* ------- Main ------- */
void		ft_new_dot(t_global *global, t_coords *lst, t_dot *dot);
t_global	*init_global_struct(t_coords *coord, int rows, int cols, int i);
t_win		*init_win(t_global *global);

int			draw(t_global *global);
int			calculate_coords(t_global *global);
void    	ft_swap(double *a, double *b);

#endif