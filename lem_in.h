/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:14:51 by hdanylev          #+#    #+#             */
/*   Updated: 2018/04/26 18:14:56 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf/inc/printf.h"

typedef struct		s_link
{
	int 			index;
	char 			*name;
	struct s_rooms	*link_room;
	struct s_link	*next;
}					t_link;

typedef struct		s_rooms
{
	int				ant_sum;
	int				x;
	int				y;
	int				lvl;
	int 			index;
	char			*name;
	struct s_rooms	*next;
	struct s_rooms	*prev;
	struct s_link	*links;
}					t_rooms;

typedef struct		s_val
{
	int 			index;
	int				ant_sum;
	int				start;
	int				end;
	int				end_room;
	int				comment;
	int				finish_room;
	int				start_room;
	int				rooms_beg;
	int				links_beg;
}					t_val;

int					validation(t_val **ant, char *line, t_rooms **rooms);
int					ant_sum(t_val **ant, char *line);
void				put_room(t_rooms **rooms, char **mass, t_val **ant);
void				put_links(t_rooms **rooms, char **mass);
void				bfs_algo(t_rooms *rooms);
t_rooms				*create_room();
int					check_links(t_val **ant, t_rooms **rooms, char *line);
t_rooms				*find_name(t_rooms **rooms, char *name);
int					free_mass(char **mass);

#endif
