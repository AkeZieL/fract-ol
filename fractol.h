/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbilly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:03:14 by mbilly            #+#    #+#             */
/*   Updated: 2023/04/08 12:46:05 by mbilly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 100
# define WIDTH 1200
# define HEIGHT 1200
# define MAX_ITER 100

typedef struct s_complex
{
	double	re;
	double	im;
}t_complex;

typedef struct s_all
{
	unsigned int	color;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	char			*name;
	char			**argv;
	int				bpp;
	int				line_length;
	int				endian;
	int				mask;
	int				julia_preset;
	double			zoom;
	double			move_x;
	double			move_y;
	t_complex		c;
}t_all;

void	how_to_use(t_all *all);
void	msg_error(t_all *all, char *s);
void	color(t_all *all, int color, int x, int y);
void	reset_fract(t_all *all);
void	julia_set(t_all *all);
void	check_before_set_julia(t_all *all);
void	take_julia_preset(t_all *all);
void	print_fractal(t_all *all);
void	render_julia2(t_all *all);
void	render_julia(t_all *all);
void	render_mandel2(t_all *all);
void	retour(t_all *all, t_complex z, double tmp);
void	render_mandelbrot(t_all *all);
void	render_mandelbrot2(t_all *all, t_complex z);
void	render_newton(t_all *all);
int		is_double(t_all *all, char *str);
int		is_point(char c);
int		ft_argvlen(char **argv);
int		mouse(int button, int x, int y, t_all *all);
int		destroy(t_all *all);
int		check_error_julia(char **argv, t_all *all);
int		check_error_newton(char **argv, t_all *all);
int		check_error_mandelbrot(char **argv, t_all *all);
int		key(int key, t_all *all);
int		ft_ispoint(char c);
int		fractal(t_all *all);
char	*ft_strjoin2(char *s1, char *s2);
char	*get_next_line(int fd);
double	ft_atof(char *str);

#endif
