/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:38:49 by hdanylev          #+#    #+#             */
/*   Updated: 2017/10/28 14:57:34 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(const char *tmp, const char *srch, int i, size_t len)
{
	int ilen;
	int	j;

	ilen = len;
	j = 0;
	while (srch[j] && i < ilen)
	{
		if (tmp[i] != srch[j])
		{
			return (tmp[i] - srch[j]);
		}
		j++;
		i++;
	}
	if (srch[j] != '\0')
		return (7);
	return (0);
}

char		*ft_strnstr(const char *tmp, const char *srch, size_t len)
{
	size_t	col;
	int		j;
	int		i;

	col = 0;
	i = 0;
	if (srch[0] == '\0')
		return ((char*)tmp);
	while (tmp[i] != '\0' && col < len)
	{
		if (tmp[i] == srch[0])
		{
			if ((j = ft_cmp(tmp, srch, i, len)) == 0)
			{
				return ((char*)&tmp[i]);
			}
		}
		i++;
		col++;
	}
	return (0);
}
