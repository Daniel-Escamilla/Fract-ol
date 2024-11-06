/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:30:45 by descamil          #+#    #+#             */
/*   Updated: 2024/10/01 17:36:27 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

// #define ZOOM_FACTOR 0.15
// #define CENTER_FACTOR 0.20
// #define MAX_ZOOM 100.0
// #define MIN_ZOOM 1e-10

// void ft_update_range(t_data *img)
// {
//     img->rango_x = img->temp.max_x - img->temp.min_x;
//     img->rango_y = img->temp.max_y - img->temp.min_y;
// }

// void ft_change_center(t_data *img, int x, int y)
// {
//     double dx = CENTER_FACTOR * (x - img->size / 2) / img->size * img->rango_x;
//     double dy = CENTER_FACTOR * (y - img->size / 2) / img->size * img->rango_y;

//     img->temp.min_x += dx;
//     img->temp.max_x += dx;
//     img->temp.min_y += dy;
//     img->temp.max_y += dy;
// }

// void ft_zoom(t_data *img, int x, int y, int zoom_type)
// {
//     ft_old_values(img);

//     double zoom_factor;
//     if (zoom_type == 1) {
//         zoom_factor = -ZOOM_FACTOR;
//     } else {
//         zoom_factor = ZOOM_FACTOR;
//     }

//     double zoom_amount_x = 0.5 * zoom_factor * img->rango_x;
//     double zoom_amount_y = 0.5 * zoom_factor * img->rango_y;

//     img->temp.max_x += zoom_amount_x;
//     img->temp.min_x -= zoom_amount_x;
//     img->temp.max_y += zoom_amount_y;
//     img->temp.min_y -= zoom_amount_y;

//     ft_update_range(img);

//     // Comprobación de límites
//     if (zoom_type == 1) // Zoom in
//     {
//         if (img->rango_x < MIN_ZOOM || img->rango_y < MIN_ZOOM)
//         {
//             img->pause = 1;
//             return;
//         }
//     }
//     else // Zoom out
//     {
//         if (img->rango_x > MAX_ZOOM || img->rango_y > MAX_ZOOM)
//         {
//             img->pause = 1;
//             return;
//         }
//     }

//     ft_change_center(img, x, y);
// }

// void ft_mouse_center(int x, int y, t_data *img, int key)
// {
//     img->rango_x = img->max_x - img->min_x;
//     img->rango_y = img->max_y - img->min_y;
//     img->escala_x = img->min_x + img->rango_x / img->size * x;
//     img->escala_y = img->min_y + img->rango_y / img->size * y;

//     if (key == 4 || key == 1)
//     {
//         ft_zoom(img, x, y, 1); // Zoom in
//     }
//     else if (key == 5 || key == 2)
//     {
//         ft_zoom(img, x, y, 0); // Zoom out
//     }
// }

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
}

int	mouse_move(int key, int x, int y, t_data *img)
{
	img->pause = 0;
	printf("%d\n", key);
	if ((key == 1 || key == 2 || key == 4 || key == 5)
		&& (x >= 0 && x < img->size && y >= 0 && y < img->size))
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
