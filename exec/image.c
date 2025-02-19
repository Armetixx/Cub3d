/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:59:02 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/02/17 12:32:01 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_heart(t_data *data, int x, int y, int size, int color) // Pour la blague, a retirer
{
	int	i;
	int	j;
    int heart_shape[7][7] = {
        {0, 1, 0, 0, 0, 1, 0},
        {1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0}
    };

	i = 0;
    while (i < 7)
    {
		j = 0;
        while (j < 7)
        {
            if (heart_shape[i][j] == 1)
                put_pixel_to_image(data, x + j * size, y + i * size, color);
			j++;
        }
		i++;
    }
}

void    put_pixel_to_image(t_data *data, int x, int y, int color)
{
    char    *dst;

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

void    render_frame(t_data *data)
{
	clear_image(data, BLACK);
    //mlx_clear_window(data->mlx_connection, data->mlx_window);
    render_3d(data); // Calcul du rendu 3D dans l'image
	draw_heart(data, WIDTH / 2 - 3, HEIGHT / 2 - 3, 2, RED);
	//draw_cursor(data, 5, RED); // curseur
    mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->img, 0, 0);
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

