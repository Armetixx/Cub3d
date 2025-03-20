/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kederhet <kederhet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:14:17 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/03/18 15:15:59 by kederhet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

//# include "../mlx_mac/mlx.h"
# include "../mlx_linux/mlx.h"
# include "errors.h"
# include "map.h"

//# include "libft/libft.h"
# include <stdio.h> // A retirer
# include <math.h>
# include "X.h"
# include "keysym.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH	1200
# define HEIGHT	700

# define ON 1
# define OFF 0

# define PLAYER_SPEED 10
# define TURN_SPEED 0.1
# define FOV 60 * (M_PI / 180) // largeur du fov
# define NUM_RAYS 100 // nombre de rays du fov
# define RAY_STEP 0.1 //distance de detection des rays
# define COLLISION 0.1 // marge d'erreur pour les collision 
# define MAX_DIST 1000 //view distance
# define PI 3.141592653589793238462

//---------- KEYS ----------//

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define M 41

//---------- COLOR ----------//

# define SKY_COLOR 0x0000FF
# define FLOOR_COLOR 0x000000

# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)
# define RED_COLOR		0xFF0000

//---------- STRUCTURE ----------//

typedef struct s_texture
{
	void	*img;
	char	*adrr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_texture;

typedef struct s_data
{
	char		*name;
	void		*mlx_connection; // mlx_init()
	void		*mlx_window; // mlx_new_window()
	char		*addr;
	void		*img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	int			**map;
	char		**tmp_map;
	int			map_x;
	int			map_y;
	int			tile_size;	
	int			map_bool;

	float		player_x;
	float		player_y;

	float		center_x;
	float		center_y;
	float		player_size;
	float		player_angle;

	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	east_texture;
	t_texture	west_texture;
	int			tex_w;
	int			tex_h;

	int			*pmap;
}	t_data;

typedef struct s_ray_hit
{
	float	distance;
	int		direction;
	float	wall_x;
}	t_ray_hit;

//---------- Events ----------//

void	events_init(t_data *data);
int		close_handler(t_data *data);
int		key_handler(int keysym, t_data *data);

//---------- INITS ----------//

void	cub3d_init(t_data*data);
void	map_init(t_data	*data);

//---------- UPDATE ----------//

void	update_game(t_data *data);
int		game_loop(t_data *data);

//---------- MAP ----------//

void	draw_map(t_data *data);
int		is_wall(t_data *data, float x, float y, int is_for_ray);

//---------- PLAYER ----------//

void	draw_player(t_data *data);
void	cast_fov(t_data *data);
void	draw_cursor(t_data *data, int size, int color);
int		ft_get_playerpos(t_data *data);

//---------- DRAWING ----------//

void	render_3d(t_data *data);
void	draw_square(t_data *data, int x, int y, int color);
void	draw_line(t_data *data, int x1, int y1, int x2, int y2, int color);
void	draw_vertical_line(t_data *data, int x, int start, int end, int color);

//---------- MLX-IMG ----------//

void	put_pixel_to_image(t_data *data, int x, int y, int color);
void	render_frame(t_data *data);
void	clear_image(t_data *data, int color);


void	load_textures(t_data *data);
int		get_texture_color(t_texture *texture, int tex_x, int tex_y);
void	draw_textured_vertical(t_data *data, int x,
			int start, int end, t_ray_hit *hit);

#endif