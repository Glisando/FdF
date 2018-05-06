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
	t_rooms	*tmp0;
	t_rooms	*tmp1;
	t_link	*lin;

	tmp0 = find_name(rooms, mass[0]);
	tmp1 = find_name(rooms, mass[1]);
	if (tmp0->index != 0 && tmp1->index != 1)
	{
		lin = (t_link*)malloc(sizeof(t_link));
		lin->next = tmp0->links;
		tmp0->links = lin;
		lin->link_room = find_name(rooms, mass[1]);
		lin->name = ft_strsub(mass[1], 0, ft_strlen(mass[1]));
		lin->index = tmp1->index;
	}
	if (tmp0->index != 1)
	{
		lin = (t_link*)malloc(sizeof(t_link));
		lin->next = tmp1->links;
		tmp1->links = lin;
		lin->link_room = find_name(rooms, mass[0]);
		lin->name = ft_strsub(mass[0], 0, ft_strlen(mass[0]));
		lin->index = tmp0->index;
	}
}

int		set_lvl_start(t_val **ant)
{
	if ((*ant)->start_room && (*ant)->start_room--)
		return (1);
	else if ((*ant)->finish_room && (*ant)->finish_room--)
		return (0);
	else
		return ((*ant)->index++);
}

void	put_room(t_rooms **rooms, char **mass, t_val **ant)
{
	t_rooms	*prev;
	t_rooms *tmp;
	int		x;
	int		y;

	x = ft_atoi(mass[1]);
	y = ft_atoi(mass[2]);
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
	tmp->index = set_lvl_start(ant);
	tmp->x = x;
	tmp->y = y;
}
