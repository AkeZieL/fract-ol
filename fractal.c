/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:54:02 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/07 14:55:41 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color(t_all *all, int color, int x, int y)
{
	char	*tmp;

	tmp = (all->addr + (y * all->line_length + x * 4));
	*(unsigned int *)tmp = color;
}

static void	init_win(t_all *all)
{
	all->mlx = mlx_init();
	if (all->mlx == (void *)0)
		exit(0);
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, all->name);
	if (all->win == (void *)0)
		exit(0);
}

int	fractal(t_all *all)
{
	if (ft_strncmp(all->name, "Julia", ft_strlen("Julia")) == 0 && \
			check_error_julia(all->argv, all) == 1)
	{
		init_win(all);
		all->c.re = ft_atof(all->argv[2]);
		all->c.im = ft_atof(all->argv[3]);
		render_julia(all);
	}
	else if (ft_strncmp(all->name, "Mandelbrot", ft_strlen("Mandelbrot")) \
			== 0 && check_error_mandelbrot(all->argv, all) == 1)
	{
		init_win(all);
		render_mandelbrot(all);
	}
	else if (ft_strncmp(all->name, "Newton", ft_strlen("Newton")) == 0 && \
			check_error_newton(all->argv, all) == 1)
	{
		init_win(all);
		render_newton(all);
	}
	return (0);
}
