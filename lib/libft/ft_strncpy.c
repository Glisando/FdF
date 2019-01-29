/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:06:00 by hdanylev          #+#    #+#             */
/*   Updated: 2017/10/31 17:23:45 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		tlen;
	int		i;
	int		j;

	tlen = len;
	i = 0;
	j = 0;
	while (j < tlen)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else
			dst[j] = '\0';
		j++;
	}
	return (dst);
}
