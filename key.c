/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:43:31 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/07 14:53:45 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy(t_all *all)
{
	mlx_clear_window(all->mlx, all->win);
	mlx_destroy_window(all->mlx, all->win);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
	free(all);
	exit(0);
	return (0);
}

static void	move_img(int key, t_all *all)
{
	if (key == 65362)
		all->move_y -= 20 / all->zoom;
	else if (key == 65364)
		all->move_y += 20 / all->zoom;
	else if (key == 65361)
		all->move_x -= 20 / all->zoom;
	else if (key == 65363)
		all->move_x += 20 / all->zoom;
}

static void	color_key(t_all *all)
{
	if (all->color == 0xFF00FF00)
		all->color = 0x00FFFFFF;
	else if (all->color == 0x00FFFFFF)
		all->color = 0x000000FF;
	else if (all->color == 0x000000FF)
		all->color = 0x0F0F00FF;
	else if (all->color == 0x0F0F00FF)
		all->color = 0x0FFF0F0F;
	else if (all->color == 0x0FFF0F0F)
		all->color = 0xFF00F0F0;
	else if (all->color == 0xFF00F0F0)
		all->color = 0xFF00FF00;
}

void	key2(int key, t_all *all)
{
	if (key == 106)
	{
		if (ft_strncmp(all->name, "Mandelbrot", ft_strlen("Madelbrot")) == 0 || \
				ft_strncmp(all->name, "Newton", ft_strlen("Newton")) == 0)
		{
			reset_fract(all);
			julia_set(all);
		}
	}
	if (key == 109)
	{
		reset_fract(all);
		all->name = "Mandelbrot";
	}
	if (key == 110)
	{
		reset_fract(all);
		all->name = "Newton";
	}
}

int	key(int key, t_all *all)
{
	if (key == 65307)
	{
		destroy(all);
		exit(0);
	}
	if (key == 65362 || key == 65364 || key == 65361 || key == 65363)
		move_img(key, all);
	if (key == 99)
		check_before_set_julia(all);
	if (key == 97)
	{
		if (ft_strncmp(all->name, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
			all->name = "Mandelbrot2";
		else if (ft_strncmp(all->name, "Julia", ft_strlen("Julia")) == 0)
			all->name = "Julia2";
	}
	if (key == 65293)
		color_key(all);
	key2(key, all);
	print_fractal(all);
	return (1);
}
