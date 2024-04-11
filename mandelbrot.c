/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:19:26 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/08 11:58:59 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	fractal_mandelbrot(t_all *all, int x, int y)
{
	t_complex	z;
	t_complex	tmp;
	int			i;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (z.re * z.re + z.im * z.im < 4 && i++ < MAX_ITER)
	{
		tmp.re = z.re * z.re - z.im * z.im + all->c.re;
		tmp.im = 2 * z.re * z.im + all->c.im;
		z = tmp;
	}
	if (i == MAX_ITER)
		color(all, 0, x, y);
	else
		color(all, (all->color & ~all->mask) * i, x, y);
	return (tmp);
}

void	render_mandelbrot(t_all *all)
{
	int	x;
	int	y;

	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->addr = mlx_get_data_addr(all->img, &all->bpp, \
			&all->line_length, &all->endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			all->c.re = x / all->zoom + all->move_x;
			all->c.im = -(y / all->zoom + all->move_y);
			fractal_mandelbrot(all, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	mlx_destroy_image(all->mlx, all->img);
}

static t_complex	fractal_mandelbrot2(t_all *all, t_complex z, int x, int y)
{
	t_complex	tmp;
	int			i;

	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i++ < MAX_ITER)
	{
		tmp.re = z.re * z.re - z.im * z.im + all->c.re;
		tmp.im = 2 * z.re * z.im + all->c.im;
		z = tmp;
	}
	if (i == MAX_ITER)
		color(all, 0, x, y);
	else
		color(all, (all->color & ~all->mask) * i, x, y);
	return (tmp);
}

void	render_mandelbrot2(t_all *all, t_complex z)
{
	int	x;
	int	y;

	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->addr = mlx_get_data_addr(all->img, &all->bpp, \
			&all->line_length, &all->endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			all->c.re = x / all->zoom + all->move_x;
			all->c.im = -(y / all->zoom + all->move_y);
			fractal_mandelbrot2(all, z, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	mlx_destroy_image(all->mlx, all->img);
}

void	render_mandel2(t_all *all)
{
	t_complex	z;
	double		tmp;

	tmp = 0;
	z.re = -2;
	z.im = 0;
	while (z.re <= 0)
	{
		all->move_x -= tmp;
		z.re += tmp * 5;
		tmp += 0.0001;
		render_mandelbrot2(all, z);
	}
	while (z.im <= 2)
	{
		all->move_x -= tmp;
		z.im += tmp * 5;
		tmp += 0.0001;
		render_mandelbrot2(all, z);
	}
	retour(all, z, tmp);
}
