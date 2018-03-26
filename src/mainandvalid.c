/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:57:02 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/18 12:54:20 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_mass(char **mass, int bef)
{
	int	elem;

	elem = 0;
	while (mass[elem])
		elem++;
	if (bef != 0 && bef != elem)
		return (0);
	return (elem);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		size;
	int		row;
	char	*line;
	char	**mass;

	if (argc != 2)
		return (write(1, "lol\n", 4));
	if ((fd = open(argv[1], O_RDONLY)) == -1 || (read(fd, NULL, 0)) == -1)
		return (write(1, "Invalid file\n", 14));
	size = 0;
	row = 0;
	while ((get_next_line(fd, &line)))
	{
		mass = ft_strsplit(line, ' ');
		if ((row = ft_mass(mass, row)) == 0)
			return (write(1, "Found wrong line length. Exiting.\n", 34));
		free(line);
		ft_free_mass(mass);
		size += row;
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	structure(fd, size, row);
	return (0);
}
