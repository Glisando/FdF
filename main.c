/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:37:26 by hdanylev          #+#    #+#             */
/*   Updated: 2018/04/17 12:37:28 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms		*create_room(void)
{
	t_rooms *rooms;

	rooms = (t_rooms*)malloc(sizeof(t_rooms));
	rooms->ant_sum = 0;
	rooms->x = -1;
	rooms->y = -1;
	rooms->lvl = 0;
	rooms->name = NULL;
	rooms->links = NULL;
	rooms->next = NULL;
	rooms->prev = NULL;
	rooms->index = 0;
	return (rooms);
}

t_val		*set_val(t_val *ant)
{
	ant->index = 2;
	ant->comment = 0;
	ant->ant_sum = 0;
	ant->start = 0;
	ant->end = 0;
	ant->rooms_beg = 0;
	ant->links_beg = 0;
	ant->start_room = 0;
	ant->finish_room = 0;
	ant->end_room = 0;
	return (ant);
}

void		printf_link(t_rooms *rooms)
{
	printf("links: ");
	while (rooms->links)
	{
		printf("%d ", rooms->links->index);
		rooms->links = rooms->links->next;
	}
	printf("\n");
}

int			main(void)
{
	char	*line;
	t_val	*ant;
	t_rooms	*rooms;

	if ((read(0, NULL, 0)) <= -1)
		return (0);
	ant = (t_val*)malloc(sizeof(t_val));
	rooms = create_room();
	ant = set_val(ant);
	while ((get_next_line(0, &line)))
	{
		printf("%s\n", line);
		if ((validation(&ant, line, &rooms)) == 0)
			return (write(1, "error\n", 6));
		free(line);
	}
	if (ant->links_beg == 0 || ant->comment)
		return (write(1, "error\n", 6));
	bfs_algo(rooms);
	printf("\n------------\n");
	while (rooms)
	{
		printf("room: %d\n", rooms->index);
		printf_link(rooms);
		printf("|\n");
		rooms = rooms->next;
	}
//	system("leaks a.out");
	return (0);
}

