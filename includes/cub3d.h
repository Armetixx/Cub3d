/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:14:17 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/02/05 12:44:58 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

//# include "../mlx_mac/mlx.h"
# include "../mlx_linux/mlx.h"
# include "../errors/errors.h"
# include "../map_checks/map.h"

//# include "libft/libft.h"
# include <stdio.h> // A retirer
# include <math.h>
# include "X.h"
# include "keysym.h"
# include <stdlib.h>
# include <unistd.h>

// Defini la taille de la window
# define WIDTH	700
# define HEIGHT	700
# define PI 3.14159265359
# define PLAYER_SPEED 5
# define TURN_SPEED 0.1
# define LINE_LENGHT 30

# define FOV 60 * (M_PI / 180)
# define NUM_RAYS 100
# define RAY_STEP 2

#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)
# define RED_COLOR		0xFF0000

typedef struct s_data
{
	char	*name;
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; // mlx_new_window()
	void	*img;

	
	float	player_x;
	float	player_y;
	float	center_x;
	float	center_y;

	int		map[10][10];
	int		map_x;
	int		map_y;
	int		*player_pos;
	int		tile_size;
	float		player_size;
	float	player_angle;
}	t_data;



int		key_handler(int keysym, t_data *data);
void	events_init(t_data *data);
int 	close_handler(t_data *data);

void	cub3d_init(t_data*data);

void	update_game(t_data *data);
int		game_loop(t_data *data);

void	map_init(t_data	*data);
void	draw_map(t_data *data);
int		is_wall(t_data *data, float x, float y);

void	draw_player(t_data *data);
void	cast_fov(t_data *data);


#endif