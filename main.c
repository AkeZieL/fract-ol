/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:50:24 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/07 14:53:22 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_tuto(void)
{
	ft_putstr_fd("\033[34;1;4mVous pouvez:\033[0m\n\n", 1);
	ft_putstr_fd("\033[32m-Changer de fractal en appuyant sur N, M ou J\n", 1);
	ft_putstr_fd("-Zoomer avec la molette\n", 1);
	ft_putstr_fd("-Fermer la fenetre en appuyant sur ESC\n", 1);
	ft_putstr_fd("-Deplacer l'image avec les fleches\n", 1);
	ft_putstr_fd("-Anime les fractales de Julia et ", 1);
	ft_putstr_fd("Mandelbrot en appuyant sur A\n", 1);
	ft_putstr_fd("-Changer de couleur en appuyant sur RETURN\033[0m\n", 1);
}

static void	init_fract(t_all *all)
{
	all->color = 0xFF00FF00;
	all->mask = 0x00F0F0F0;
	all->zoom = 200;
	all->move_x = -2.8;
	all->move_y = -2.8;
	all->julia_preset = 0;
	fractal(all);
}

static void	set_name(t_all *all)
{
	if (ft_strncmp(all->argv[1], "Julia", ft_strlen("Julia")) == 0)
		all->name = "Julia";
	else if (ft_strncmp(all->argv[1], "Mandelbrot", \
				ft_strlen("Mandelbrot")) == 0)
		all->name = "Mandelbrot";
	else if (ft_strncmp(all->argv[1], "Newton", ft_strlen("Newton")) == 0)
		all->name = "Newton";
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	all->name = "TEST";
	if (argc > 1)
	{
		all->argv = argv;
		set_name(all);
	}
	if (ft_strncmp(all->name, "TEST", ft_strlen(all->name)) != 0)
	{
		init_fract(all);
		print_tuto();
		mlx_mouse_hook(all->win, mouse, all);
		mlx_key_hook(all->win, key, all);
		mlx_hook(all->win, 17, 1L << 0, &destroy, all);
		mlx_loop(all->mlx);
	}
	else
		how_to_use(all);
}
