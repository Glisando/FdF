/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:56:51 by hdanylev          #+#    #+#             */
/*   Updated: 2018/05/01 18:56:57 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_old_link(t_rooms **rooms, char **mass, int thesame)
{
	t_link	*ptr1;
	t_link	*ptr2;
	t_rooms	*tmp1;
	t_rooms	*tmp2;

	tmp1 = find_name(rooms, mass[0]);
	tmp2 = find_name(rooms, mass[1]);
	ptr1 = tmp1->links;
	ptr2 = tmp2->links;
	while (ptr1)
	{
		if ((ft_strequ(ptr1->name, mass[1])))
			thesame++;
		ptr1 = ptr1->next;
	}
	while (ptr2)
	{
		if ((ft_strequ(ptr2->name, mass[0])))
			thesame++;
		ptr2 = ptr2->next;
	}
	if (thesame > 0)
		return (0);
	return (1);
}

int		check_links(t_val **ant, t_rooms **rooms, char *line)
{
	t_rooms	*tmp;
	char	**mass;
	int		count;

	(*ant)->comment = 0;
	if ((*ant)->rooms_beg == 0 || (*ant)->end != 1 || (*ant)->start != 1)
		return (0);
	if ((*ant)->links_beg == 0)
		(*ant)->links_beg = 1;
	count = 0;
	mass = ft_strsplit(line, '-');
	tmp = (*rooms);
	while (tmp)
	{
		if (ft_strequ(tmp->name, mass[0]) || ft_strequ(tmp->name, mass[1]))
			count++;
		tmp = tmp->next;
	}
	if (count != 2 || !check_old_link(rooms, mass, 0))
		return (0); // You can try build a way from here ...
	put_links(rooms, mass);
	free_mass(mass);
	return (1);
}
