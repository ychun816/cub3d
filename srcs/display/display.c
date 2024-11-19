/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:31:23 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/19 17:46:02 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	display(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->so_xpm, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->no_xpm, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->we_xpm, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->ea_xpm, 0, 0);
	return (0 + 0);
}
