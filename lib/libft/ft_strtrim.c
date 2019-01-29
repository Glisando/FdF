/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:47:03 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 16:10:09 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_revclean(const char *str, int c)
{
	int cc;

	cc = 0;
	c = c - 1;
	while (str[c] == '\n' || str[c] == ' ' || str[c] == '\t')
	{
		cc++;
		c--;
	}
	if (c == -1)
	{
		c = 0;
		return (c);
	}
	return (cc);
}

static int	ft_clean(const char *str, int k)
{
	while (str[k] == '\n' || str[k] == ' ' || str[k] == '\t')
		k++;
	return (k);
}

char		*ft_strtrim(char const *str)
{
	int		ch;
	int		i;
	int		j;
	char	*fresh;

	if (str == NULL)
		return (0);
	ch = ft_strlen(str);
	i = ft_revclean(str, ch);
	j = ft_clean(str, 0);
	ch = ch - (i + j);
	fresh = (char*)malloc(ch + 1);
	if (fresh)
	{
		i = 0;
		while (i < ch)
			fresh[i++] = str[j++];
		fresh[i] = '\0';
		return (fresh);
	}
	return (0);
}
