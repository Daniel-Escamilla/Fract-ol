/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:05:06 by descamil          #+#    #+#             */
/*   Updated: 2024/11/22 17:21:27 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_isnum(char *str)
{
	int	dot_count;
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	dot_count = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_argc_4(t_data *img, char *argv2, char *argv3)
{
	img->c_julia_r = ft_atof(argv2);
	img->c_julia_i = ft_atof(argv3);
	if (((ft_isnum(argv2) == 0 || ft_isnum(argv3) == 0))
		|| img->c_julia_r < -2.00000 || img->c_julia_r > 2.00000
		|| img->c_julia_i < -2.00000 || img->c_julia_i > 2.00000)
	{
		write(2, "Write: julia '-2.0 <-> 2.0' '-2.0 <-> 2.0'\n", 43);
		write(2, "Recomended: \n", 13);
		write(2, "--> [-0.1\t 0.87]\n", 18);
		write(2, "--> [ 0.285\t-0.01]\n", 20);
		write(2, "--> [-0.72\t-0.196]\n", 20);
		write(2, "--> [-0.51\t-0.601]\n", 20);
		write(2, "--> [-1.3\t 0.00525]\n", 21);
		write(2, "Error\n", 7);
		return (0);
	}
	img->empty = 1;
	return (1);
}

int	end_program(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

int	ft_name(t_data *img)
{
	if ((ft_strncmp(img->name, "mandel", 6) == 0) && ft_strlen(img->name) == 6)
		return (0);
	if ((ft_strncmp(img->name, "julia", 5) == 0) && ft_strlen(img->name) == 5)
		return (0);
	if ((ft_strncmp(img->name, "bonus", 5) == 0) && ft_strlen(img->name) == 5)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	img;

	ft_set_values(&img);
	if (argv && argv[1])
		img.name = argv[1];
	if (argc == 4 && ft_strncmp(img.name, "julia", 5) == 0
		&& ft_strlen(img.name) == 5)
	{
		if (ft_argc_4(&img, argv[2], argv[3]) == 0)
			return (1);
	}
	if ((argc != 2 && argc != 4) || ft_name(&img) == 1)
	{
		write(2, "Write: 'mandel' o 'julia [x y]' o 'bonus'\nError\n", 49);
		return (1);
	}
	ft_create_window(&img);
	draw_fractal(&img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_mouse_hook(img.mlx_win, mouse_move, &img);
	mlx_hook(img.mlx_win, 17, 0, end_program, &img);
	mlx_loop(img.mlx);
}
