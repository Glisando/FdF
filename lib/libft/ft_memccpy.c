/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:50:12 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/02 14:12:16 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		i;
	size_t				t;
	unsigned char		*arr;
	const unsigned char	*data;

	i = (unsigned char)c;
	t = 0;
	arr = (unsigned char*)dst;
	data = (const unsigned char*)src;
	while (t < n)
	{
		if (data[t] == i)
		{
			arr[t] = data[t];
			return ((unsigned char*)&arr[t + 1]);
		}
		arr[t] = data[t];
		t++;
	}
	return (0);
}
