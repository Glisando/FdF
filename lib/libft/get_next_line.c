/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:21:21 by hdanylev          #+#    #+#             */
/*   Updated: 2017/12/19 15:07:54 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_index(char *content)
{
	int index;
	int	len;

	len = ft_strlen(content);
	index = 0;
	while (index < len)
	{
		if (content[index] == '\n')
			return (index);
		index++;
	}
	return (index);
}

t_list	*ft_read(int fd, t_list *run, char **line, char *tmp)
{
	char	buf[BUFF_SIZE + 1];
	int		count;
	int		index;

	while ((count = read(fd, buf, BUFF_SIZE)))
	{
		buf[count] = '\0';
		tmp = run->content;
		run->content = ft_strjoin(run->content, buf);
		ft_strdel(&tmp);
		if ((index = ft_index(run->content)) < count)
			break ;
	}
	index = ft_index(run->content);
	*line = ft_strsub(run->content, 0, index);
	tmp = run->content;
	if ((size_t)index < ft_strlen(run->content))
		index += 1;
	run->content = ft_strsub(run->content, index, ft_strlen(run->content));
	ft_strdel(&tmp);
	if (*line[0] == '\0' && index == count)
		run->content_size = 9999;
	return (run);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file = NULL;
	t_list			*run;

	if (read(fd, NULL, 0) == -1)
		return (-1);
	run = file;
	while ((run && (int)(run->content_size) != fd))
		run = run->next;
	if (run == NULL)
	{
		run = ft_lstnew("", 1);
		run->content_size = fd;
		ft_lstadd(&file, run);
	}
	run = ft_read(fd, run, line, NULL);
	if (run->content_size == 9999)
		return (0);
	return (1);
}
