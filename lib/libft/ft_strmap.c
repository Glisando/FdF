/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:34:20 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/01 12:45:59 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	int		i;
	char	*ptr;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	ptr = (char*)malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		ptr[i] = f(str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
