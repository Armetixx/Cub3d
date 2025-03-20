/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcools <gcools@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 03:02:09 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/20 15:38:29 by gcools           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

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
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	sx = -1;
	sy = -1;
	if (x1 < x2)
		sx = 1;
	if (y1 < y2)
		sy = 1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	err = dx - dy;
	while (x1 != x2 || y1 != y2)
	{
		put_pixel_to_image(data, x1, y1, color);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
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

void	draw_textured_vertical(t_data *data, int x, int start,
										int end, t_ray_hit *hit)
{
	int			y;
	t_texture	*texture;
	int			tex_x;
	int			tex_y;
	int			color;

	if (hit->direction == 0)
		texture = &data->north_texture;
	else if (hit->direction == 1)
		texture = &data->south_texture;
	else if (hit->direction == 2)
		texture = &data->east_texture;
	else if (hit->direction == 3)
		texture = &data->west_texture;
	else
		texture = &data->north_texture;
	tex_x = (int)(hit->wall_x * data->tex_w);
	y = 0;
	while (y < HEIGHT)
	{
		if (y < start)
			put_pixel_to_image(data, x, y, SKY_COLOR);
		else if (y > end)
			put_pixel_to_image(data, x, y, FLOOR_COLOR);
		else
		{
			tex_y = (int)((y - start) / (float)(end - start)
					*data->tex_h);
			color = get_texture_color(texture, tex_x, tex_y);
			put_pixel_to_image(data, x, y, color);
		}
		y++;
	}
}
