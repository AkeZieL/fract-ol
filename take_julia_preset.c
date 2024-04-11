/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_julia_preset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:52:36 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/06 14:39:29 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_julia_preset(t_all *all)
{
	if (all->julia_preset == 1)
	{
		all->c.re = -0.56;
		all->c.im = 0.395;
	}
	else if (all->julia_preset == 2)
	{
		all->c.re = -0.4;
		all->c.im = 0.6;
	}
	else if (all->julia_preset == 3)
	{
		all->c.re = -1.4170222;
		all->c.im = 0.00995;
	}
	else if (all->julia_preset == 4)
	{
		all->c.re = 0.3;
		all->c.im = 0.5;
	}
	else if (all->julia_preset == 5)
	{
		all->c.re = 0.285;
		all->c.im = 0.01;
	}
}

void	check_before_set_julia(t_all *all)
{
	if (ft_strncmp(all->name, "Julia", ft_strlen("Julia")) == 0)
		take_julia_preset(all);
}

void	take_julia_preset(t_all *all)
{
	if (all->julia_preset == 0)
		all->julia_preset = 1;
	else if (all->julia_preset == 1)
		all->julia_preset = 2;
	else if (all->julia_preset == 2)
		all->julia_preset = 3;
	else if (all->julia_preset == 3)
		all->julia_preset = 4;
	else if (all->julia_preset == 4)
		all->julia_preset = 5;
	else if (all->julia_preset == 5)
		all->julia_preset = 1;
	all->name = "Julia";
	init_julia_preset(all);
}
