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

int		ft_masslen(char **mass)
{
	int len;

	len = 0;
	while (mass[len])
		len++;
	return (len);
}

void	ft_read_file(int fd, int x, int y, char *line)
{
	char		**mass;
	int			x_end;
	t_coords	*coord;
	t_coords	*tmp;

	coord = (t_coords*)malloc(sizeof(t_coords));
	tmp = coord;
	while (get_next_line(fd, &line))
	{
		mass = ft_strsplit(line, ' ');
		x_end = ft_masslen(mass);
		x = -1;
		while (++x < x_end)
		{
			tmp->next = (t_coords*)malloc(sizeof(t_coords));
			tmp = tmp->next;
			tmp->x = x;
			tmp->y = y;
			tmp->z = ft_atoi(mass[x]);
			tmp->color = ft_strchr(mass[x], 'x') == 0 ?
				0xfffff2 : ft_atoi_base(ft_strchr(mass[x], 'x'), 16);
			printf("x: %i | y: %i | z: %i | color: %x\n", tmp->x, tmp->y, tmp->z, tmp->color);
		}
		y++;
	}
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (write(1, "Wrong number of arguments\n", 27));
	if ((fd = open(argv[1], O_RDONLY)) == -1 || (read(fd, NULL, 0)) == -1)
		return (write(1, "Invalid file\n", 14));
	ft_read_file(fd, 0, 0, NULL);
	return (0);
}
