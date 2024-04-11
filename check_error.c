/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:52:34 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/07 14:56:06 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage_error(t_all *all)
{
	ft_putstr_fd("\033[31;1;4mErreur dans les arguments\n\n", 2);
	ft_putstr_fd("\033[32;4mArgument:\n\n\033[0m", 2);
	ft_putstr_fd("\033[32mJulia -> val1 -> val2\n", 2);
	ft_putstr_fd("----------------------------\n", 2);
	ft_putstr_fd("\033[32mMandelbrot\n", 2);
	ft_putstr_fd("----------------------------\n", 2);
	ft_putstr_fd("\033[32mNewton\n\033[0m", 2);
	free(all);
	exit(0);
}

void	msg_error(t_all *all, char *s)
{
	ft_putstr_fd(s, 2);
	free(all);
	exit(0);
}

int	check_error_mandelbrot(char **argv, t_all *all)
{
	if (ft_argvlen(argv) == 2)
		return (1);
	else
		usage_error(all);
	return (0);
}

int	check_error_newton(char **argv, t_all *all)
{
	if (ft_argvlen(argv) == 2)
		return (1);
	else
		usage_error(all);
	return (0);
}

int	check_error_julia(char **argv, t_all *all)
{
	if (ft_argvlen(argv) == 4)
	{
		if (is_double(all, argv[2]) == 0)
			msg_error(all, "\033[31mLe premier nombre n'est pas un double\n");
		if (is_double(all, argv[3]) == 0)
			msg_error(all, "\033[31mLe deuxieme nombre n'est pas un double\n");
	}
	else
		usage_error(all);
	return (1);
}
