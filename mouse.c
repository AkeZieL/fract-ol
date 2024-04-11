/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:05:25 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/07 14:40:39 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int x, int y, t_all *all)
{
	all->move_x = (x / all->zoom + all->move_x) - (x / (all->zoom * 1.20));
	all->move_y = (y / all->zoom + all->move_y) - (y / (all->zoom * 1.20));
	all->zoom = all->zoom * 1.20;
}

void	unzoom(int x, int y, t_all *all)
{
	all->move_x = (x / all->zoom + all->move_x) - (x / (all->zoom / 1.20));
	all->move_y = (y / all->zoom + all->move_y) - (y / (all->zoom / 1.20));
	all->zoom = all->zoom / 1.20;
}

void	reset_fract(t_all *all)
{
	all->zoom = 200;
	all->move_x = -2.8;
	all->move_y = -2.8;
}

void	print_fractal(t_all *all)
{
	if (ft_strncmp(all->name, "Julia", ft_strlen("Julia1")) == 0)
		render_julia(all);
	else if (ft_strncmp(all->name, "Mandelbrot", ft_strlen("Mandelbrot1")) == 0)
		render_mandelbrot(all);
	else if (ft_strncmp(all->name, "Newton", ft_strlen("Newton")) == 0)
		render_newton(all);
	else if (ft_strncmp(all->name, "Julia2", ft_strlen("Julia2")) == 0)
		render_julia2(all);
	else if (ft_strncmp(all->name, "Mandelbrot2", ft_strlen("Mandelbrot2")) \
			== 0)
		render_mandel2(all);
}

int	mouse(int button, int x, int y, t_all *all)
{
	if (button == 4)
		zoom(x, y, all);
	else if (button == 5)
		unzoom(x, y, all);
	print_fractal(all);
	return (1);
}
