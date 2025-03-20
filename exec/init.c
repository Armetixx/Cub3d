/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:18:33 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/20 16:37:03 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

void	events_init(t_data *data)
{
	mlx_loop_hook(data->mlx_connection, game_loop, data);
	mlx_hook(data->mlx_window, KeyPress, KeyPressMask, key_handler, data);
	mlx_hook(data->mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, data);
}

void	cub3d_init(t_data*data)
{
	data->name = "cub3d";
	data->mlx_connection = mlx_init();
	if (data->mlx_connection == NULL)
		malloc_error();
	data->mlx_window = mlx_new_window(data->mlx_connection,
			WIDTH, HEIGHT, data->name);
	if (data->mlx_window == NULL)
	{
		mlx_destroy_window(data->mlx_window, data->mlx_connection);
		free(data->mlx_connection);
		malloc_error();
	}
	data->img = mlx_new_image(data->mlx_connection, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->tex_w = 64;
	data->tex_h = 64;
	load_textures(data);
}

void	load_textures(t_data *data)
{
	data->north_texture.img = mlx_xpm_file_to_image(data->mlx_connection,
			data->north, &data->tex_w, &data->tex_h);
	data->north_texture.adrr = mlx_get_data_addr(data->north_texture.img,
			&data->north_texture.bits_per_pixel,
			&data->north_texture.line_lenght,
			&data->north_texture.endian);
	data->south_texture.img = mlx_xpm_file_to_image(data->mlx_connection,
			data->south, &data->tex_w, &data->tex_h);
	data->south_texture.adrr = mlx_get_data_addr(data->south_texture.img,
			&data->south_texture.bits_per_pixel,
			&data->south_texture.line_lenght,
			&data->south_texture.endian);
	data->east_texture.img = mlx_xpm_file_to_image(data->mlx_connection,
			data->east, &data->tex_w, &data->tex_h);
	data->east_texture.adrr = mlx_get_data_addr(data->east_texture.img,
			&data->east_texture.bits_per_pixel,
			&data->east_texture.line_lenght,
			&data->east_texture.endian);
	data->west_texture.img = mlx_xpm_file_to_image(data->mlx_connection,
			data->west, &data->tex_w, &data->tex_h);
	data->west_texture.adrr = mlx_get_data_addr(data->west_texture.img,
			&data->west_texture.bits_per_pixel,
			&data->west_texture.line_lenght,
			&data->west_texture.endian);
}

int	get_texture_color(t_texture *texture, int tex_x, int tex_y)
{
	char	*pixel;

	if (tex_x < 0)
		tex_x = 0;
	if (tex_y < 0)
		tex_y = 0;
	pixel = texture->adrr + (tex_y * texture->line_lenght
			+ tex_x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}
