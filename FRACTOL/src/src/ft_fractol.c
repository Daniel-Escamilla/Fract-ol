/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:05:06 by descamil          #+#    #+#             */
/*   Updated: 2024/01/11 18:02:51 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_argc_4(t_data *img, char *argv2, char *argv3)
{
	img->c_julia_r = ft_atof(argv2);
	img->c_julia_i = ft_atof(argv3);
	if ((img->c_julia_r < -2.0 || img->c_julia_r > 2.0)
		|| (img->c_julia_i < -2.0 || img->c_julia_i > 2.0))
	{
		write(1, "Write: julia '-2.0 <-> 2.0' '-2.0 <-> 2.0'\n", 43);
		write(1, "Recomended: \n", 13);
		write(1, "--> [-0.1\t 0.87]\n", 18);
		write(1, "--> [ 0.285\t-0.01]\n", 20);
		write(1, "--> [-0.72\t-0.196]\n", 20);
		write(1, "--> [-0.51\t-0.601]\n", 20);
		write(1, "--> [-1.3\t 0.00525]\n", 21);
		return (0);
	}
	return (1);
}

int	end_program(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_win);
	exit (0);
}

int	main(int argc, char *argv[])
{
	t_data	img;

	if (argc < 2)
		return (0);
	ft_set_values(&img);
	img.name = argv[1];
	if (argc == 4 && ft_strncmp(img.name, "julia", 6) == 0)
	{
		if (ft_argc_4(&img, argv[2], argv[3]) == 0)
			return (0);
	}	
	else if (((ft_strncmp(img.name, "mandel", 7) != 0)
		&& (ft_strncmp(img.name, "julia", 6) != 0)
		&& (ft_strncmp(img.name, "bonus", 6) != 0))
		|| argc == 3 || argc > 4)
	{
		write(1, "Write: 'mandel' o 'julia [x y]' o 'bonus'\n", 43);
		return (0);
	}
	ft_create_window(&img);
	draw_fractal(&img);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_hook(img.mlx_win, 4, 0, mouse_move, &img);
	mlx_hook(img.mlx_win, 5, 0, mouse_move, &img);
	mlx_hook(img.mlx_win, 17, 0, end_program, &img);
	mlx_loop(img.mlx);
}
