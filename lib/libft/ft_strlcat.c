/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:50:10 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/04 13:07:24 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_rlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t			ft_strlcat(char *s1, const char *s2, size_t dstsize)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	j = 0;
	len1 = ft_rlen(s1);
	len2 = ft_rlen(s2);
	i = len1;
	if (dstsize < len1)
		return (dstsize + len2);
	while ((i < dstsize - 1) && s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (len1 + len2);
}
