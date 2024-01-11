/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:05:06 by descamil          #+#    #+#             */
/*   Updated: 2024/01/09 18:30:30 by descamil         ###   ########.fr       */
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
	// printf("MIN-X = %f\n", img->min_x);
	// printf("MAX-X = %f\n", img->max_x);
	// printf("MIN-Y = %f\n", img->min_y);
	// printf("MAX-Y = %f\n", img->max_y);
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

void	ft_change_center(t_data *img, int x, int y)
{
	img->temp.min_x += 0.20 * (x - img->size / 2) / img->size * img->rango_x;
	img->temp.max_x += 0.20 * (x - img->size / 2) / img->size * img->rango_x;
	img->temp.min_y += 0.20 * (y - img->size / 2) / img->size * img->rango_y;
	img->temp.max_y += 0.20 * (y - img->size / 2) / img->size * img->rango_y;
}

void	ft_zoom_in(t_data *img, int x, int y)
{
	ft_old_values(img);
	if ((img->temp.max_x <= img->zero && img->temp.min_x >= -img->zero)
		|| (img->temp.max_y <= img->zero && img->temp.min_y >= -img->zero)
		|| (img->rango_x < img->zero || img->rango_y < img->zero))
	{
		img->pause = 1;
		return ;
	}
	img->temp.max_x -= 0.5 * 0.15 * img->rango_x;
	img->temp.min_x += 0.5 * 0.15 * img->rango_x;
	img->temp.max_y -= 0.5 * 0.15 * img->rango_y;
	img->temp.min_y += 0.5 * 0.15 * img->rango_y;
	ft_change_center(img, x, y);
}

void	ft_zoom_out(t_data *img, int x, int y)
{
	ft_old_values(img);
	if ((img->temp.max_x > 100 && img->temp.min_x < -100)
		|| (img->temp.max_y > 100 && img->temp.min_y < -100))
	{
		img->pause = 1;
		return ;
	}
	img->temp.max_x += 0.5 * 0.15 * img->rango_x;
	img->temp.min_x -= 0.5 * 0.15 * img->rango_x;
	img->temp.max_y += 0.5 * 0.15 * img->rango_y;
	img->temp.min_y -= 0.5 * 0.15 * img->rango_y;
	ft_change_center(img, x, y);
}

void	ft_mouse_center(int x, int y, t_data *img, int key)
{
	img->rango_x = img->max_x - img->min_x;
	img->rango_y = img->max_y - img->min_y;
	img->escala_x = (img->min_x + img->rango_x / img->size * x); 
	img->escala_y = (img->min_y + img->rango_y / img->size * y);
	if (key == 4 || key == 1)
		ft_zoom_in(img, x, y);
	else if (key == 5 || key == 2)
		ft_zoom_out(img, x, y);
	// printf("X = %d\n", x);
	// printf("Y = %d\n", y);
	// printf("%d\n", img->pause);
}

int	mouse_move(int key, int x, int y, t_data *img)
{
	img->pause = 0;
	if ((key == 1 || key == 2 || key == 4 || key == 5) &&
		(x >= 0 && x < img->size && y >= 0 && y < img->size))
	{
		if (key == 4 || key == 1)
			ft_mouse_center(x, y, img, key);
		else if (key == 5 || key == 2)
			ft_mouse_center(x, y, img, key);
		else if (img->pause == 1)
			return (0);
		else
			return (0);
		ft_new_values(img);
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
	img->max_x = 2.0;
	img->min_x = -2.0;
	img->max_y = 2.0;
	img->min_y = -2.0;
	img->c_julia_r = 0.000000;
	img->c_julia_i = 0.000000;
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
	if (argc == 4 && ft_strncmp(argv[2], "video", 6) == 0 && ft_strncmp(img.name, "julia", 6) == 0)
	{
		char	*line;
		int		fd;
		char	**valores;
		
		img.archivo = argv[3];
		printf("%s\n", img.archivo);
		fd = open(img.archivo, O_RDONLY);
		line = get_next_line(fd);
		valores = ft_split(line, ' ');
		free(line);
		img.c_julia_r = ft_atof(valores[0]);
		img.c_julia_i = ft_atof(valores[1]);
		if ((img.c_julia_r < -2.0 || img.c_julia_r > 2.0)
			|| (img.c_julia_i < -2.0 || img.c_julia_i > 2.0))
		{
			write (1, "Cambia los parametros del archivo\n", 35);
			return (0);
		}
		img.frame_i = 1;
		close(fd);
	}
	else if (argc == 4 && ft_strncmp(img.name, "julia", 6) == 0)
	{
		img.c_julia_r = ft_atof(argv[2]);
		img.c_julia_i = ft_atof(argv[3]);
		if ((img.c_julia_r < -2.0 || img.c_julia_r > 2.0)
			|| (img.c_julia_i < -2.0 || img.c_julia_i > 2.0))
		{
			write (1, "Write: julia '-2.0 <-> 2.0' '-2.0 <-> 2.0'\n", 44);
			return (0);
		}
	}
	else if ((ft_strncmp(img.name, "mandel", 7) != 0)
		&& (ft_strncmp(img.name, "julia", 6) != 0)
		&& (ft_strncmp(img.name, "bonus", 6) != 0))
	{
		write(1, "Write: 'mandel' o 'julia' o 'bonus'\n", 37);
		return (0);
	}
	ft_create_window(&img);
	draw_fractal(&img);
		
	img.fd2 = open(img.archivo, O_RDONLY);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_hook(img.mlx_win, 4, 0, mouse_move, &img);
	mlx_hook(img.mlx_win, 5, 0, mouse_move, &img);
	// mlx_mouse_pos(img.mlx_win, );
	mlx_hook(img.mlx_win, 17, 0, end_program, &img);
	mlx_loop(img.mlx);
}

// 4 = Scroll up;
// 5 = Scroll down;