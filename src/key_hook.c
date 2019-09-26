/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 13:09:35 by hdanylev          #+#    #+#             */
/*   Updated: 2019/07/05 13:09:37 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook(int key, t_global *params)
{
	bool	changed;

	changed = false;
	(key == 53) ? exit(1) : NULL;
	if (key == 124 && (changed = true))
		params->b += 2 * 0.0174533;
	else if (key == 123 && (changed = true))
		params->b -= 2 * 0.0174533;
	else if (key == 126 && (changed = true))
		params->a += 2 * 0.0174533;
	else if (key == 125 && (changed = true))
		params->a -= 2 * 0.0174533;
	else if (key == 115 && (changed = true))
		params->c -= 2 * 0.0174533;
	else if (key == 119 && (changed = true))
		params->c += 2 * 0.0174533;
	else if (key == 69 && (changed = true))
		params->scale += 0.6;
	else if (key == 78 && (changed = true))
		params->scale -= 0.6;
	else
		hook2(key, params, &changed);
	(changed == true) ? new_image(params) : NULL;
	return (0);
}

void	hook2(int key, t_global *params, bool *changed)
{
	if (key == 18 && (*changed = true))
	{
		params->a = 30 * 0.0174533;
		params->b = 30 * 0.0174533;
		params->c = 30 * 0.0174533;
	}
	else if (key == 19 && (*changed = true))
	{
		params->a = 0 * 0.0174533;
		params->b = 0 * 0.0174533;
		params->c = 0 * 0.0174533;
	}
	else if (key == 20 && (*changed = true))
	{
		params->a = 90 * 0.0174533;
		params->b = 90 * 0.0174533;
		params->c = 90 * 0.0174533;
	}
	else if (key == 21 && (*changed = true))
	{
		params->a = 90 * 0.0174533;
		params->b = 90 * 0.0174533;
		params->c = 0 * 0.0174533;
	}
	hook3(key, params, changed);
}

void	hook3(int key, t_global *params, bool *changed)
{
	if (key == 27 && (*changed = true))
		altitude_changing(params->coord, 0.97);
	else if (key == 24 && (*changed = true))
		altitude_changing(params->coord, 1.03);
	else if (key == 83 && (*changed = true))
		set_magma_color(params->coord);
	else if (key == 84 && (*changed = true))
		set_ukr_color(params->coord);
	else if (key == 85 && (*changed = true))
		set_purple_color(params->coord);
	else if (key == 86 && (*changed = true))
		set_orange_color(params->coord);
}
