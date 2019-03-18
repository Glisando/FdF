/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:37:55 by hdanylev          #+#    #+#             */
/*   Updated: 2019/03/12 16:37:56 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

t_coords	*ft_new_list(t_coords *tmp, int x, int y, char **mass)
{
	tmp->next = (t_coords*)malloc(sizeof(t_coords));
	tmp = tmp->next;
	tmp->x = x;
	tmp->y = y;
	tmp->z = ft_atoi(mass[x]);
	tmp->color = ft_strchr(mass[x], 'x') == 0 ?
		0xfffff2 : ft_atoi_base(ft_strchr(mass[x], 'x'), 16);
	return (tmp);
}

t_win		*init_win(int rows, int cols, int size, double scale)
{
	t_win	*win;

	win = (t_win*)malloc(sizeof(t_win));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, size * scale,
		size * scale, "---- HOT FDF ----");
	win->img = mlx_new_image(win->mlx, rows, cols);
	return (win);
}

t_global	*init_global_struct(t_coords *coord, int rows, int cols)
{
	t_global *global;

	global = (t_global*)malloc(sizeof(t_global));
	global->a = 20;
	global->b = 20;
	global->c = 20;
	global->scale = 15;
	global->rows = rows;
	global->cols = cols;
	global->size = rows * cols;
	global->coord = coord;
	global->dot = (t_dot**)malloc(sizeof(t_dot*) * rows);
	global->win = init_win(rows, cols, global->size, global->scale);
	printf("rows: %u\n", rows);
	return (global);
}

int			ft_read_file(int fd, unsigned int x,
				unsigned int y, t_coords *coord)
{
	char			*line;
	char			**mass;
	unsigned int	cols;
	unsigned int	prev_cols;
	t_coords		*tmp;

	tmp = coord;
	prev_cols = 0;
	while (get_next_line(fd, &line))
	{
		mass = ft_strsplit(line, ' ');
		cols = ft_arraylen(mass);
		if (cols == 0 || (cols != prev_cols && prev_cols != 0))
			return (write(1, "Error: Invalid string :(\n", 25));
		x = -1;
		while (++x < cols)
			tmp = ft_new_list(tmp, x, y, mass);
		ft_free_2array(mass);
		ft_strdel(&line);
		prev_cols = cols;
		y++;
	}
	return (calculate_coords(init_global_struct(coord, y, cols)));
}

int			main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (write(1, "Error: Wrong number of arguments\n", 33));
	if ((fd = open(argv[1], O_RDONLY)) == -1 || (read(fd, NULL, 0)) == -1)
		return (write(1, "Error: Invalid file\n", 19));
	ft_read_file(fd, 0, 0, (t_coords*)malloc(sizeof(t_coords)));
	return (0);
}
