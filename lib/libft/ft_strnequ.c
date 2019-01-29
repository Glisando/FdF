/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:11:11 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/01 12:02:46 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t len)
{
	size_t i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && i < len)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}
