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

t_coords	*ft_new_list(t_coords *tmp, unsigned int x,
				unsigned int y, char **mass)
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

int			ft_read_file(int fd, unsigned int x,
				unsigned int y, t_coords *coord)
{
	char			*line;
	char			**mass;
	unsigned int	x_max;
	t_coords		*tmp;

	tmp = coord;
	while (get_next_line(fd, &line))
	{
		mass = ft_strsplit(line, ' ');
		x_max = ft_arraylen(mass);
		if (x_max == 0)
			return (write(1, "Error: Empty string :(\n", 23));
		tmp->cols = x_max;
		x = -1;
		while (++x < x_max)
		{
			tmp = ft_new_list(tmp, x, y, mass);
			tmp->cols = x_max;
		}
		ft_free_2array(mass);
		ft_strdel(&line);
		y++;
	}
	return (calculate_coords(init_global_struct(coord, y), 0));
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
