/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 10:42:32 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/07 14:35:48 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	retour(t_all *all, t_complex z, double tmp)
{
	tmp = 0;
	z.re = 2;
	while (z.re > 0)
	{
		all->move_x += tmp;
		z.im -= tmp * 5;
		z.re -= tmp * 5;
		tmp += 0.0001;
		render_mandelbrot2(all, z);
	}
	z.im = 0;
	while (z.re >= -2)
	{
		all->move_x += tmp;
		z.re -= tmp * 5;
		tmp += 0.0001;
		render_mandelbrot2(all, z);
	}
}

static void	check_set_julia(t_all *all, char **tmp)
{
	int	i;

	i = 0;
	while (tmp[1][i] != '\n')
		i++;
	tmp[1][i] = '\0';
	if (is_double(all, tmp[0]) == 1)
		all->c.re = ft_atof(tmp[0]);
	else
		msg_error(all, "Le premier nombre n'est pas un double");
	if (is_double(all, tmp[1]) == 1)
		all->c.im = ft_atof(tmp[1]);
	else
		msg_error(all, "Le deuxieme nombre n'est pas un double");
	all->name = "Julia";
}

static void	free_split(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	julia_set(t_all *all)
{
	char	**tmp;
	char	*line;

	ft_putstr_fd("\033[34;4;1m\nVoulez vous utilisez vos propre valeur ?\033[0m\n"\
			, 1);
	ft_putstr_fd("\033[32mOui ou Non\033[0m\n", 1);
	line = get_next_line(0);
	if (ft_strncmp(line, "Oui", ft_strlen("Oui")) == 0)
	{
		ft_putstr_fd("\033[34;4;1m\nChoisissez vos valeur\033[0m\n", 1);
		ft_putstr_fd("\033[32mValeur_reel Valeur_Imaginaire\n\033[0m", 1);
		free(line);
		line = get_next_line(0);
		tmp = ft_split(line, ' ');
		free(line);
		check_set_julia(all, tmp);
		free_split(tmp);
	}
	else
	{
		free(line);
		ft_putstr_fd("\033[34;4;1mVous pouvez changer de ", 1);
		ft_putstr_fd("preset en appuyant sur C\033[0m\n", 1);
		take_julia_preset(all);
	}
}
