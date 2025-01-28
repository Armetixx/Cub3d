/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:14:17 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/01/28 12:33:33 by guillaumeco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
//# include "libft/libft.h"
# include <stdio.h> // A retirer
# include <math.h>
# include "X.h"
# include "keysym.h"
# include <stdlib.h>
# include <unistd.h>

// Defini la taille de la window
# define WIDTH	1200
# define HEIGHT	750

typedef struct s_data
{
	char	*name;
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; // mlx_new_window()
	void	*wall;
	void	*player_x;
	void	*player_y;
	char	**map;
	int		*player_pos;
}	t_data;

void	cub3d_init(t_data*data);
int 	close_handler(t_data *data);
int		key_handler(int keysym, t_data *data);


#endif