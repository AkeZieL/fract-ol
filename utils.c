/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:21:41 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/13 11:05:10 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	how_to_use(t_all *all)
{
	ft_putstr_fd("\033[34;1;4mComment utiliser le programme ?\033[0m\n\n", 2);
	ft_putstr_fd("\033[32m./fractol arguments\n\n", 2);
	ft_putstr_fd("\033[34;1;4mIl existe 3 differents arguments:\033[0m\n\n", 2);
	ft_putstr_fd("\033[32mJulia Valeur1 Valeur2\n", 2);
	ft_putstr_fd("\033[32m----------------------\n", 2);
	ft_putstr_fd("\033[32mMandelbrot\n", 2);
	ft_putstr_fd("\033[32m----------------------\n", 2);
	ft_putstr_fd("\033[32mNewton\n\033[0m", 2);
	free(all);
	exit(1);
}

int	ft_ispoint(char c)
{
	if (c == '.')
		return (1);
	else
		return (0);
}

double	ft_atof(char *str)
{
	int		signe;
	double	res;
	double	decimal;

	decimal = 10.0;
	signe = 1;
	res = ft_atoi(str);
	if (str[0] == '-')
		signe = -1;
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '\0')
		return (res);
	str++;
	while (*str)
	{
		res = res + ((*str - '0') / decimal * signe);
		decimal = decimal * 10;
		str++;
	}
	return (res);
}

int	is_double(t_all *all, char *str)
{
	int	i;
	int	j;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if (ft_ispoint(str[i]) == 0)
				return (0);
			else if (ft_ispoint(str[i]) == 1)
			{
				j = i + 1;
				while (str[j])
				{
					if (ft_ispoint(str[j++]) == 1)
						msg_error(all, "\033[31mIl y a 2 point dans un nombre\n");
				}
			}
		}
	}
	return (1);
}

int	ft_argvlen(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
