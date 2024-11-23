/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:07 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/23 13:44:21 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->p_dir.x;
	data->p_dir.x = data->p_dir.x * cos(ROTATE_SPEED) - data->p_dir.y
		* sin(ROTATE_SPEED);
	data->p_dir.y = old_dir_x * sin(ROTATE_SPEED) + data->p_dir.y
		* cos(ROTATE_SPEED);
	old_plane_x = data->cam_plane.x;
	data->cam_plane.x = data->cam_plane.x * cos(ROTATE_SPEED)
		- data->cam_plane.y * sin(ROTATE_SPEED);
	data->cam_plane.y = old_plane_x * sin(ROTATE_SPEED) + data->cam_plane.y
		* cos(ROTATE_SPEED);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->p_dir.x;
	data->p_dir.x = data->p_dir.x * cos(-ROTATE_SPEED) - data->p_dir.y
		* sin(-ROTATE_SPEED);
	data->p_dir.y = old_dir_x * sin(-ROTATE_SPEED) + data->p_dir.y
		* cos(-ROTATE_SPEED);
	old_plane_x = data->cam_plane.x;
	data->cam_plane.x = data->cam_plane.x * cos(-ROTATE_SPEED)
		- data->cam_plane.y * sin(-ROTATE_SPEED);
	data->cam_plane.y = old_plane_x * sin(-ROTATE_SPEED) + data->cam_plane.y
		* cos(-ROTATE_SPEED);
}

int	input(int keysim, t_cube *cube)
{
	if (keysim == XK_Escape)
		return (cleanup(cube, 0), 0);
	if (keysim == XK_Left)
		rotate_left(cube->data);
	if (keysim == XK_Right)
		rotate_right(cube->data);
	mlx_clear_window(cube->mlx, cube->mlx_win);
	display(cube);
	return (0);
}

int	close_window(t_cube *cube)
{
	return (cleanup(cube, 0), 0);
}
