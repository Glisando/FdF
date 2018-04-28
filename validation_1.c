/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:15:18 by hdanylev          #+#    #+#             */
/*   Updated: 2018/04/26 18:15:19 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_coord(t_rooms **rooms, char **mass, int x, int y)
{
	t_rooms	*tmp;

	tmp = (*rooms);
	while (tmp)
	{
		if (ft_strequ(tmp->name, mass[0]) || (tmp->x == x && tmp->y == y))
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (1);
	free_mass(mass);
	return (0);
}

int		room(t_val **ant, char *line, t_rooms **rooms)
{
	int		i;
	int		x;
	int		y;
	char	**mass;

	if ((*ant)->rooms_beg == 0)
		(*ant)->rooms_beg++;
	mass = ft_strsplit(line, ' ');
	if ((*ant)->links_beg == 1 || (*ant)->ant_sum == 0)
		return (0);
	i = 0;
	while (mass[++i])
		if ((ft_strdigit(mass[i])))
			return (0);
	if (i != 3)
		return (0);
	x = ft_atoi(mass[1]);
	y = ft_atoi(mass[2]);
	if ((check_coord(rooms, mass, x, y)) == 0)
		return (0);
	put_room(rooms, mass, x, y);
	return (1);
}

int		comments(t_val **ant, char *line)
{
	int		i;

	i = 0;
	if ((*ant)->end_room == 1)
		return (0);
	while (line[i] == '#')
		i++;
	if ((ft_strequ(&line[i], "start") && i == 2))
	{
		(*ant)->start++;
		(*ant)->start_room = 1;
	}
	else if ((ft_strequ(&line[i], "end") && i == 2))
	{
		(*ant)->end++;
		(*ant)->end_room = 1;
	}
	return (1);
}

int		ant_sum(t_val **ant, char *line)
{
	int		i;
	char	*tmp;

	i = ft_atoi(line);
	tmp = ft_itoa(i);
	if ((ft_strequ(tmp, line)))
	{
		if (!((*ant)->ant_sum = (*ant)->ant_sum == 0 ? ft_atoi(line) : 0))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		validation(t_val **ant, char *line, t_rooms **rooms)
{
	int space;
	int def;
	int i;

	def = 0;
	space = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			def++;
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (line[0] == '#')
		return (comments(ant, line));
	else if (space == 2 && def == 0)
		return (room(ant, line, rooms));
	else if (def == 1 && space == 0)
		return (check_links(ant, rooms, line));
	else if (line[0] >= '0' && line[0] <= '9' && space == 0)
		return (ant_sum(ant, line));
	return (0);
}
