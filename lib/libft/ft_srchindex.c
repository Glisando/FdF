/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:14:59 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 11:20:04 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_srchindex(char *tmp, char *srch, int i)
{
	int	j;

	j = 0;
	while (srch[j])
	{
		if (tmp[i] != srch[j])
		{
			return (tmp[i] - srch[j]);
		}
		j++;
		i++;
	}
	return (0);
}
