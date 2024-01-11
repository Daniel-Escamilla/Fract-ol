/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_values.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:46:25 by descamil          #+#    #+#             */
/*   Updated: 2024/01/11 17:00:17 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_create_window(t_data *img)
{
	img->mlx = mlx_init();
	if (img->mlx == NULL)
		exit (1);
	img->mlx_win = mlx_new_window(img->mlx, img->size, img->size, img->name);
	if (img->mlx_win == NULL)
	{
		end_program(img);
		exit (1);
	}
	img->img = mlx_new_image(img->mlx, img->size, img->size);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	draw_fractal(t_data *img)
{
	img->x = 0;
	while (img->x < img->size)
	{
		img->y = 0;
		while (img->y < img->size)
		{
			if (ft_strncmp(img->name, "mandel", 7) == 0)
				my_mlx_pixel_put(img, img->x, img->y, ft_make_mandel(img));
			else if (ft_strncmp(img->name, "julia", 6) == 0)
				my_mlx_pixel_put(img, img->x, img->y, ft_make_julia(img));
			else if (ft_strncmp(img->name, "bonus", 5) == 0)
				my_mlx_pixel_put(img, img->x, img->y, ft_make_bonus(img));
			else
				return ;
			img->y++;
		}
		img->x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

void	ft_new_values(t_data *img)
{
	img->max_x = img->temp.max_x;
	img->min_x = img->temp.min_x;
	img->max_y = img->temp.max_y;
	img->min_y = img->temp.min_y;
}

void	ft_old_values(t_data *img)
{
	img->temp.max_x = img->max_x;
	img->temp.min_x = img->min_x;
	img->temp.max_y = img->max_y;
	img->temp.min_y = img->min_y;
}

void	ft_set_values(t_data *img)
{
	img->max_x = 2.0;
	img->min_x = -2.0;
	img->max_y = 2.0;
	img->min_y = -2.0;
	img->c_julia_r = 0.000000;
	img->c_julia_i = 0.000000;
	img->size = 550;
	img->max_iterations = 350;
	img->color = 16777216;
	img->color2 = 8192;
	img->zero = 0.000001;
}
