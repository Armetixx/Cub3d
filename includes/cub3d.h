/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaumecools <guillaumecools@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:14:17 by guillaumeco       #+#    #+#             */
/*   Updated: 2025/01/22 15:34:11 by guillaumeco      ###   ########.fr       */
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
#define WIDTH	800
#define HEIGHT	800

typedef struct s_cub3d
{
	char	*name;
	void	*mlx_connection; // mlx_init()
	void	*mlx_window; // mlx_new_window()

}	t_cub3d;

void	cub3d_init(t_cub3d *cub3d);
int 	close_handler(t_cub3d *cub3d);
int		key_handler(int keysym, t_cub3d *cub3d);

#endif