/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 03:02:09 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/13 14:11:07 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < data->tile_size)
	{
		j = 0;
		while (j < data->tile_size)
		{
			if (i == 0 || j == 0)
				put_pixel_to_image(data, x + j, y + i, BLACK); // Bordures en noir
			else
				put_pixel_to_image(data, x + j, y + i, color); // Intérieur coloré
			j++;
		}
		i++;
	}
}

void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int	sx = (x1 < x2) ? 1 : -1;
	int	sy = (y1 < y2) ? 1 : -1;
	int	err = dx - dy;
	int e2;

	while (x1 != x2 || y1 != y2)
	{
		put_pixel_to_image(data, x1, y1, color);
		e2 = 2 * err;
		if (e2 > -dy) { err -= dy; x1 += sx; }
		if (e2 < dx) { err += dx; y1 += sy; }
	}
}

void	draw_vertical_line(t_data *data, int x, int start, int end, int color)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < start)
			put_pixel_to_image(data, x, y, SKY_COLOR);
		else if (y > end)
			put_pixel_to_image(data, x, y, FLOOR_COLOR);
		else
			put_pixel_to_image(data, x, y, color);
		y++;
	}
}

void draw_textured_vertical(t_data *data, int x, int start, int end, t_ray_hit *hit)
{
    int y;
    t_texture *texture;
    int tex_x, tex_y;
    int color;
    
    // Select texture based on wall direction
    switch (hit->direction) {
        case 0: texture = &data->north_texture; break;
        case 1: texture = &data->south_texture; break;
        case 2: texture = &data->east_texture; break;
        case 3: texture = &data->west_texture; break;
        default: texture = &data->north_texture;
    }
    
    tex_x = (int)(hit->wall_x * data->texture_width);
    
    y = 0;
    while (y < HEIGHT)
    {
        if (y < start)
            put_pixel_to_image(data, x, y, SKY_COLOR);
        else if (y > end)
            put_pixel_to_image(data, x, y, FLOOR_COLOR);
        else
        {
            float wall_height = end - start;
            tex_y = (int)((y - start) / wall_height * data->texture_height);
            
            color = get_texture_color(texture, tex_x, tex_y);
            put_pixel_to_image(data, x, y, color);
        }
        y++;
    }
}