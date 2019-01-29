/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:14:00 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/01 11:57:38 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int		i;

	i = 0;
	if (str == NULL || f == NULL)
		return ;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
