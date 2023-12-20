/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main-pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: descamil <descamil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:52:39 by descamil          #+#    #+#             */
/*   Updated: 2023/12/04 17:06:15 by descamil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;

// }	t_data;

// int main()
// {
//     void	*mlx;
//     void	*mlx_win;
//     t_data	img;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1200, 800, "Hello");
//     img.img = mlx_new_image(mlx, 1200, 800);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     my_mlx_pixel_put(&img, 20, 50, 0x00FF00FF);
//     mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 300);

//     mlx_loop(mlx);
// }