/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:59:02 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/20 18:23:55 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	render_frame(t_data *data)
{
	clear_image(data, BLACK);
	render_3d(data);
	draw_cursor(data, 5, RED);
	mlx_put_image_to_window(data->mlx_connection,
		data->mlx_window, data->img, 0, 0);
}

void	clear_image(t_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel_to_image(data, x, y, color);
			x++;
		}
		y++;
	}
}
