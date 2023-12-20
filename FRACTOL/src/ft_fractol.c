/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:05:06 by descamil          #+#    #+#             */
/*   Updated: 2023/12/20 19:35:38 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

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
	img->MAX_X = img->temp.MAX_X;
	img->MIN_X = img->temp.MIN_X;
	img->MAX_Y = img->temp.MAX_Y;
	img->MIN_Y = img->temp.MIN_Y;
}

void	ft_zoom_in(t_data *img)
{
	img->temp.MAX_X = img->MAX_X;
	img->temp.MIN_X = img->MIN_X;
	img->temp.MAX_Y = img->MAX_Y;
	img->temp.MIN_Y = img->MIN_Y;
	img->temp.MAX_X -= 0.5 * 0.15 * img->rango_x;
	img->temp.MIN_X += 0.5 * 0.15 * img->rango_x;
	img->temp.MAX_Y -= 0.5 * 0.15 * img->rango_y;
	img->temp.MIN_Y += 0.5 * 0.15 * img->rango_y;
}

void	ft_zoom_out(t_data *img)
{
	img->temp.MAX_X = img->MAX_X;
	img->temp.MIN_X = img->MIN_X;
	img->temp.MAX_Y = img->MAX_Y;
	img->temp.MIN_Y = img->MIN_Y;
	img->temp.MAX_X += 0.5 * 0.15 * img->rango_x;
	img->temp.MIN_X -= 0.5 * 0.15 * img->rango_x;
	img->temp.MAX_Y += 0.5 * 0.15 * img->rango_y;
	img->temp.MIN_Y -= 0.5 * 0.15 * img->rango_y;
}

int	mouse_move(int key, int x, int y, t_data *img)
{
	img->rango_x = img->MAX_X - img->MIN_X;
	img->rango_y = img->MAX_Y - img->MIN_Y;
	if ((key == 4 || key == 5 || key == 1 || key == 2) &&
		(x >= 0 && x < img->size && y >= 0 && y < img->size)
		&& (img->rango_x > img->zero && img->rango_y > img->zero))
	{
		if (key == 4 || key == 1)
		{
			ft_zoom_in(img);
			if ((img->temp.MAX_X <= img->zero && img->temp.MIN_X >= -img->zero)
				|| (img->temp.MAX_Y <= img->zero && img->temp.MIN_Y >= -img->zero))
			{
				ft_zoom_out(img);
				return (0);
			}
		}
		else if (key == 5 || key == 2)
		{
			// ft_fractal_mouse_center(img);
			// {
			ft_zoom_out(img);
			if ((img->temp.MAX_X <= img->zero && img->temp.MIN_X >= -img->zero)
				|| (img->temp.MAX_Y <= img->zero && img->temp.MIN_Y >= -img->zero))
			{	
				ft_zoom_in(img);
				return (0);
			}
			// }
		}
		else
			return (0);
		ft_new_values(img);
		printf("MIN_X	%f\n", round(img->MIN_X));
		printf("MAX_X	 %f\n", round(img->MAX_X));
		printf("MIN_Y	%f\n", round(img->MIN_Y));
		printf("MAX_Y	 %f\n", round(img->MAX_Y));
		printf("RANGO_X		%f\n", img->rango_x);
		printf("RANGO_Y		%f\n", img->rango_y);
	}
	draw_fractal(img);
	return (0);
}

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
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

}

void	ft_set_values(t_data *img)
{
	img->MAX_X = 2.0;
	img->MIN_X = -2.0;
	img->MAX_Y = 2.0;
	img->MIN_Y = -2.0;
	img->zoom_factor = 1.0;
	img->zoom = 1.5;
	img->size = 550;
	img->max_iterations = 150;
	img->color = 16777216;
	img->color2 = 8192;
	img->zero = 0.000001;
}

int	main(int argc, char *argv[])
{
	t_data	img;
	
	if (argc < 2)
		return (0);
	ft_set_values(&img);
	img.name = argv[1];
	img.argc = argc;
	if (argc == 4 && ft_strncmp(img.name, "julia", 6) == 0)
	{
		img.c_julia_r = ft_atof(argv[2]);
		img.c_julia_i = ft_atof(argv[3]);
	}
	else
	{
		img.c_julia_r = 0.000000;
		img.c_julia_i = 0.000000;
	}
	if (img.argc > 4 && ft_strncmp(img.name, "julia", 6) == 0)
	{
		write (1, "Write: julia '2.0 <-> -2.0' '2.0 <-> -2.0'\n", 44);
		return (0);
	}
	if ((ft_strncmp(img.name, "mandel", 7) != 0)
		&& (ft_strncmp(img.name, "julia", 6) != 0)
		&& (ft_strncmp(img.name, "bonus", 6) != 0))
	{
		write(1, "Write: 'mandel' o 'julia' o 'bonus'\n", 37);
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


// 4 = Scroll up;
// 5 = Scroll down;