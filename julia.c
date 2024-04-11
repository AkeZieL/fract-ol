/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:16:26 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/07 14:54:52 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	fractal_julia(t_all *all, t_complex z, int x, int y)
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
		color(all, (all->color - all->mask) * i, x, y);
	return (tmp);
}

void	render_julia(t_all *all)
{
	t_complex	z;
	int			x;
	int			y;

	all->img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	all->addr = mlx_get_data_addr(all->img, &all->bpp, \
			&all->line_length, &all->endian);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = x / all->zoom + all->move_x;
			z.im = y / all->zoom + all->move_y;
			fractal_julia(all, z, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	mlx_destroy_image(all->mlx, all->img);
}

void	render_julia2(t_all *all)
{
	double	tmp;

	all->move_x = -2;
	all->c.im = -1.5;
	tmp = 0;
	while (all->c.im <= 1.5)
	{
		all->c.im += tmp;
		all->move_x -= tmp;
		tmp += 0.0001;
		render_julia(all);
	}
}
