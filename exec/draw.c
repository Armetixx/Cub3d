/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 03:02:09 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/21 17:32:15 by kederhet         ###   ########.fr       */
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
				put_pixel_to_image(data, x + j, y + i, BLACK);
			else
				put_pixel_to_image(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_put_image(t_data *data, int x2, int y2)
{
	int	x1;
	int	y1;

	x1 = (int)data->center_x;
	y1 = (int)data->center_y;
	while (x1 != x2 || y1 != y2)
	{
		put_pixel_to_image(data, x1, y1, RED_COLOR);
		data->e2 = 2 * data->err;
		if (data->e2 > -data->dy)
		{
			data->err -= data->dy;
			x1 += data->sx;
		}
		if (data->e2 < data->dx)
		{
			data->err += data->dx;
			y1 += data->sy;
		}
	}
}

void	draw_line(t_data *data, int x2, int y2)
{
	int	x1;
	int	y1;

	x1 = (int)data->center_x;
	y1 = (int)data->center_y;
	data->sx = -1;
	data->sy = -1;
	if (x1 < x2)
		data->sx = 1;
	if (y1 < y2)
		data->sy = 1;
	data->dx = abs(x2 - x1);
	data->dy = abs(y2 - y1);
	data->err = data->dx - data->dy;
	ft_draw_put_image(data, x2, y2);
}

void	ft_draw_texture(t_data *data, int x, t_texture *texture, int tex_x)
{
	int	y;
	int	start;
	int	color;
	int	tex_y;

	y = 0;
	data->rgbceiling = ft_convert_rgb(data->ceiling);
	data->rgbfloor = ft_convert_rgb(data->floor);
	start = ((HEIGHT / 2) - (data->wall_height / 2));
	while (y < HEIGHT)
	{
		if (y < start)
			put_pixel_to_image(data, x, y, data->rgbceiling);
		else if (y > ((HEIGHT / 2) + (data->wall_height / 2)))
			put_pixel_to_image(data, x, y, data->rgbfloor);
		else
		{
			tex_y = (int)((y - start) / (float)(((HEIGHT / 2)
							+ (data->wall_height / 2)) - start) *data->tex_h);
			color = get_texture_color(texture, tex_x, tex_y);
			put_pixel_to_image(data, x, y, color);
		}
		y++;
	}
}

void	draw_textured_vertical(t_data *data, int x,
			float wall_height, t_ray_hit *hit)
{
	t_texture	*texture;
	int			tex_x;

	data->wall_height = wall_height;
	if (hit->direction == 0)
		texture = &data->north_texture;
	else if (hit->direction == 1)
		texture = &data->south_texture;
	else if (hit->direction == 3)
		texture = &data->east_texture;
	else if (hit->direction == 2)
		texture = &data->west_texture;
	else
		texture = &data->north_texture;
	tex_x = (int)(hit->wall_x * data->tex_w);
	ft_draw_texture(data, x, texture, tex_x);
}
