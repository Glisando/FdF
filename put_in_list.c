/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:28:48 by hdanylev          #+#    #+#             */
/*   Updated: 2018/04/26 14:28:53 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms	*find_name(t_rooms **rooms, char *name)
{
	t_rooms	*tmp;

	tmp = (*rooms);
	while (tmp)
	{
		if ((ft_strequ(tmp->name, name)))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	put_links(t_rooms **rooms, char **mass)
{
	t_rooms	*tmp;
	t_link	*lin;

	if (mass[0][0] != '0' && mass[1][0] != '1')
	{
		tmp = find_name(rooms, mass[0]);
		lin = (t_link *) malloc(sizeof(t_link));
		lin->next = tmp->links;
		tmp->links = lin;
		lin->link_room = find_name(rooms, mass[1]);
		lin->name = ft_strsub(mass[1], 0, ft_strlen(mass[1]));
	}
	if (mass[0][0] != '1')
	{
		tmp = find_name(rooms, mass[1]);
		lin = (t_link *) malloc(sizeof(t_link));
		lin->next = tmp->links;
		tmp->links = lin;
		lin->link_room = find_name(rooms, mass[0]);
		lin->name = ft_strsub(mass[0], 0, ft_strlen(mass[0]));
	}
}

void	put_room(t_rooms **rooms, char **mass, int x, int y)
{
	t_rooms	*prev;
	t_rooms *tmp;

	tmp = (*rooms);
	prev = NULL;
	if (tmp->name != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_room();
		prev = tmp;
		tmp = tmp->next;
		tmp->prev = prev;
		tmp->next = NULL;
	}
	tmp->name = ft_strsub(mass[0], 0, ft_strlen(mass[0]));
	tmp->x = x;
	tmp->y = y;
	free_mass(mass);
}
