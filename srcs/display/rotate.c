/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:36:56 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/28 15:37:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_left(t_data *data)
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

void	rotate_right(t_data *data)
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
