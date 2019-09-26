/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:37:26 by hdanylev          #+#    #+#             */
/*   Updated: 2019/07/06 18:37:27 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_magma_color(t_coords *coord)
{
	t_coords *lst;

	lst = coord;
	while (lst)
	{
		lst->color = lst->z > 0 ? MAGMA_E : MAGMA_S;
		lst = lst->next;
	}
}

void	set_ukr_color(t_coords *coord)
{
	t_coords *lst;

	lst = coord;
	while (lst)
	{
		lst->color = lst->z > 0 ? UKR_E : UKR_S;
		lst = lst->next;
	}
}

void	set_purple_color(t_coords *coord)
{
	t_coords *lst;

	lst = coord;
	while (lst)
	{
		lst->color = lst->z > 0 ? PURPLE_E : PURPLE_S;
		lst = lst->next;
	}
}

void	set_orange_color(t_coords *coord)
{
	t_coords *lst;

	lst = coord;
	while (lst)
	{
		lst->color = lst->z > 0 ? ORANGE_E : ORANGE_S;
		lst = lst->next;
	}
}

void	print_hot_keys(void)
{
	system("clear");
	ft_printf("🔥 🔥 🔥 🔥 🔥 🔥 🔥 HOT KEYS 🔥 🔥 🔥 🔥 \
🔥 🔥 🔥 🔥 \n\n");
	ft_printf("🔥     Keys 1,2,3,4 (top)    - change projection   🔥 \n");
	ft_printf("🔥     Keys 1,2,3,4 (side)   - change color        🔥 \n");
	ft_printf("🔥     Keys - and + (top)    - change depth        🔥 \n");
	ft_printf("🔥     Keys - and + (side)   - change scale        🔥 \n");
	ft_printf("🔥     Arrows                - rotation            🔥 \n\n");
	ft_printf("🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥 🔥\n");
}
