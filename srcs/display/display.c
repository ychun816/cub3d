/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:07 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/18 16:48:18 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	input(int keysim, t_cube *cube)
{
	if (keysim == XK_Escape)
		return (cleanup(cube, 0), 0);
	return (0);
}

int	close_window(t_cube *cube)
{
	return (cleanup(cube, 0), 0);
}

void	display(t_cube *cube)
{
	cube->mlx = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	mlx_key_hook(cube->mlx_win, &input, cube);
	mlx_hook(cube->mlx_win, 17, 0, close_window, cube);
	mlx_loop(cube->mlx);
}
