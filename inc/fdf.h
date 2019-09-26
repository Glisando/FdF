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

# define MAGMA_S 0xa12424
# define MAGMA_E 0xffdb00
# define UKR_S 0x1875de
# define UKR_E 0xe6d51e
# define PURPLE_S 0xb41ee6
# define PURPLE_E 0x1e32e6
# define ORANGE_S 0xfff4ed
# define ORANGE_E 0xed7528

typedef struct		s_dl
{
	bool			steep;
	int				xpxl1;
	int				ypxl1;
	int				xpxl2;
	int				ypxl2;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	double			dx;
	double			dy;
	double			gradient;
	double			xend;
	double			yend;
	double			xgap;
	double			intery;
}					t_dl;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	unsigned int	*img;
}					t_win;

typedef struct		s_coords
{
	double			x;
	double			y;
	double			z;
	int				color;
	struct s_coords	*next;
}					t_coords;

typedef struct		s_dot
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_dot;

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
	int				xend;
	int				yend;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	double			a;
	double			b;
	double			c;
	double			t[3][3];
	double			scale;
	double			per;
	t_dl			dr;
	t_coords		*coord;
	t_dot			**dot;
	t_win			*win;
}					t_global;

void				percentage(t_global *global, int xcurrent, int ycurrent);
double				percent(int start, int end, int current);
int					get_light(int start, int end, double percentage);
int					get_color(int start, int end, t_global *global);

double				rfpart(double x);
double				fpart(double x);
double				round(double x);
int					ipart(double x);
void				plot(double x, double y, double c, t_global *global);

void				ft_free_2array(char **mass);
void				altitude_changing(t_coords *coord, double sign);
void				ft_rotate_matrix(t_global *global);
int					ft_arraylen(char **mass);
void				new_image(t_global *global);
void				ft_swap(double *a, double *b);
bool				check_coord1(t_global *global, int i, int j);
bool				check_coord2(t_global *global, int i, int j);
void				zero_dl(t_global *global);
void				set_dot0(t_dot **dot, int i, int j, t_global *global);
void				set_dot1(t_dot **dot, int i, int j, t_global *global);

int					hook(int key, t_global *params);
void				hook2(int key, t_global *params, bool *changed);
void				hook3(int key, t_global *params, bool *changed);

void				ft_new_dot(t_global *global, t_coords *lst, t_dot *dot);
t_global			*init_global_struct(t_coords *coord, int rows,
											int cols, int i);
t_win				*init_win(t_global *global);

int					draw(t_global *global, t_dot **dot, int j, int i);
void				drawline(t_global *global);
int					calculate_coords(t_global *global);
void				ft_swap(double *a, double *b);
void				set_magma_color(t_coords *coord);
void				set_purple_color(t_coords *coord);
void				set_ukr_color(t_coords *coord);
void				set_orange_color(t_coords *coord);
void				print_hot_keys(void);

#endif
