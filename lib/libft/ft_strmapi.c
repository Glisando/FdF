/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:58:47 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/01 12:46:36 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
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
		ptr[i] = f(i, str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
