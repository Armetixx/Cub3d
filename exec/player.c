/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:53:23 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/13 14:35:20 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Fonction pour la map en 2D
void	cast_ray(t_data *data, float angle)
{
	float	ray_x;
	float	ray_y;

	ray_x = data->player_x + data->player_size / 2;
	ray_y = data->player_y + data->player_size / 2;
	while (!is_wall(data, ray_x, ray_y, 1))
	{
		ray_y += cos(angle) * RAY_STEP;
		ray_x += sin(angle) * RAY_STEP;
	}
	draw_line(data, (int)data->center_x, (int)data->center_y, (int)ray_x, (int)ray_y, RED_COLOR);
}

t_ray_hit cast_ray_textured(t_data *data, float angle)
{
    float ray_x, ray_y, prev_x, prev_y;
    float step_x, step_y;
    t_ray_hit hit;
    
    ray_x = data->player_x;
    ray_y = data->player_y;
    step_x = sin(angle) * RAY_STEP;
    step_y = cos(angle) * RAY_STEP;
    
    hit.distance = 0;
    
    while (!is_wall(data, ray_x, ray_y, 1) && hit.distance < MAX_DIST)
    {
        prev_x = ray_x;
        prev_y = ray_y;
        ray_x += step_x;
        ray_y += step_y;
        hit.distance += RAY_STEP;
    }
    
    // Determine which wall face was hit
    float dx = ray_x - prev_x;
    float dy = ray_y - prev_y;
    
    if (fabs(dy) > fabs(dx)) {
        // Horizontal wall (North/South)
        if (dy > 0) {
            hit.direction = 0; // North
        } else {
            hit.direction = 1; // South
        }
        hit.wall_x = fmod(ray_x, data->tile_size) / data->tile_size;
    } else {
        // Vertical wall (East/West)
        if (dx > 0) {
            hit.direction = 3; // West
        } else {
            hit.direction = 2; // East
        }
        hit.wall_x = fmod(ray_y, data->tile_size) / data->tile_size;
    }
    
    return hit;
}
void	cast_fov(t_data *data)
{
	int	i;
	float	start_angle;
	float	angle_step;

	i = 0;
	start_angle = data->player_angle - (FOV / 2);
	angle_step = FOV / NUM_RAYS;
	while (i < NUM_RAYS)
	{
		cast_ray(data, start_angle + i * angle_step);
		i++;
	}
}
t_ray_hit cast_ray_dda(t_data *data, float angle)
{
    t_ray_hit hit;
    
    // Ray direction
    float ray_dir_x = sin(angle);
    float ray_dir_y = cos(angle);
    
    // Current map position
    int map_x = (int)(data->player_x / data->tile_size);
    int map_y = (int)(data->player_y / data->tile_size);
    
    // Distance to next grid line
    float side_dist_x;
    float side_dist_y;
    
    // Distance between grid lines
    float delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
    float delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);
    
    // Direction to step
    int step_x;
    int step_y;
    
    // Calculate step and initial side_dist
    if (ray_dir_x < 0) {
        step_x = -1;
        side_dist_x = (data->player_x / data->tile_size - map_x) * delta_dist_x;
    } else {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - data->player_x / data->tile_size) * delta_dist_x;
    }
    
    if (ray_dir_y < 0) {
        step_y = -1;
        side_dist_y = (data->player_y / data->tile_size - map_y) * delta_dist_y;
    } else {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - data->player_y / data->tile_size) * delta_dist_y;
    }
    
    // Perform DDA
    int hit_wall = 0;
    int side; // 0 = x-side, 1 = y-side
    
    while (!hit_wall) {
        // Jump to next grid square
        if (side_dist_x < side_dist_y) {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0;
        } else {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1;
        }
        
        // Check if ray hit a wall
        if (map_x < 0 || map_y < 0 || map_x >= data->map_x || map_y >= data->map_y)
            break;
        
        if (data->map[map_y][map_x] == 1)
            hit_wall = 1;
    }
    
    // Calculate distance
    float wall_dist;
    if (side == 0)
        wall_dist = (side_dist_x - delta_dist_x);
    else
        wall_dist = (side_dist_y - delta_dist_y);
    
    // Calculate wall hit position for texturing
    float wall_x;
    if (side == 0)
        wall_x = data->player_y / data->tile_size + wall_dist * ray_dir_y;
    else
        wall_x = data->player_x / data->tile_size + wall_dist * ray_dir_x;
    
    wall_x -= floor(wall_x);
    
    // Set wall direction
    if (side == 0) {
        if (step_x > 0)
            hit.direction = 2; // East
        else
            hit.direction = 3; // West
    } else {
        if (step_y > 0)
            hit.direction = 0; // North
        else
            hit.direction = 1; // South
    }
    
    hit.distance = wall_dist * data->tile_size;
    hit.wall_x = wall_x;
    
    return hit;
}

// Update render_3d to use DDA
void render_3d(t_data *data)
{
    int i;
    float ray_angle;
    t_ray_hit hit;
    float wall_height;
    int wall_top, wall_bottom;
    
    i = 0;
    while (i < WIDTH)
    {
        ray_angle = data->player_angle - (FOV / 2) + (i / (float)WIDTH) * FOV;
        hit = cast_ray_dda(data, ray_angle);
        
        // Apply fisheye correction
        hit.distance *= cos(ray_angle - data->player_angle);
        
        wall_height = (data->tile_size * HEIGHT) / (hit.distance + 0.0001);
        if (wall_height > HEIGHT)
            wall_height = HEIGHT;
        
        wall_top = (HEIGHT / 2) - (wall_height / 2);
        wall_bottom = (HEIGHT / 2) + (wall_height / 2);
        
        draw_textured_vertical(data, i, wall_top, wall_bottom, &hit);
        
        i++;
    }
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	
	data->center_x = data->player_x + data->player_size / 2;
	data->center_y = data->player_y + data->player_size / 2;
	i = 0;
	while (i < data->player_size)
	{
		j = 0;
		while (j < data->player_size)
		{
			put_pixel_to_image(data, data->player_x + i, data->player_y + j, BLUE);
			//mlx_pixel_put(data->mlx_connection, data->mlx_window, data->player_x + i, data->player_y + j, BLUE);
			j++;
		}
		i++;
	}	
}

void draw_cursor(t_data *data, int size, int color)
{
    int center_x = WIDTH / 2;
    int center_y = HEIGHT / 2;
    int i;

    i = -size;
    while (i <= size)
	{
        put_pixel_to_image(data, center_x + i, center_y, color);
		i++;
	}
	i = -size;
    while (i <= size)
	{
        put_pixel_to_image(data, center_x, center_y + i, color);
		i++;
	}
}
