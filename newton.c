/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:16:29 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/07 14:39:20 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	t_complex	complex_div(t_complex *a, t_complex *b)
{
	double		d;
	t_complex	res;

	d = b->re * b->re + b->im * b->im;
	res.re = (a->re * b->re + a->im * b->im) / d;
	res.im = (a->im * b->re - a->re * b->im) / d;
	return (res);
}

static void	f_et_fprime(t_complex *z, t_complex *f, t_complex *fprime)
{
	f->re = (z->re * z->re * z->re) - (3 * z->re * z->im * z->im) - 1;
	f->im = (3 * z->re * z->re * z->im) - (z->im * z->im * z->im);
	fprime->re = (3 * z->re * z->re) - (3 * z->im * z->im);
	fprime->im = (6 * z->re * z->im);
}

static void	fractal_newton(t_all *all, t_complex z, int x, int y)
{
	t_complex	tmp;
	t_complex	f;
	t_complex	fprime;
	int			i;

	i = 0;
	while (i++ < MAX_ITER)
	{
		f_et_fprime(&z, &f, &fprime);
		if (fprime.re == 0 && fprime.im == 0)
			break ;
		tmp = complex_div(&f, &fprime);
		z.re = (z.re - tmp.re);
		z.im = (z.im - tmp.im);
		if (z.re < -4.0 || z.re > 4.0 || z.im < -4.0 || z.im > 4.0)
			break ;
		if (fabs(tmp.re - z.re) < 0.0001 && fabs(tmp.im - z.im) < 0.0001)
			break ;
	}
	if (i == MAX_ITER)
		color(all, 0, x, y);
	else
		color(all, (all->color - all->mask) * i, x, y);
}

void	render_newton(t_all *all)
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
			fractal_newton(all, z, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	mlx_destroy_image(all->mlx, all->img);
}
