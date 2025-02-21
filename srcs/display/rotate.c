/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:36:56 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/21 16:15:27 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_left(t_data *data, double rotation_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->p_dir.x;
	data->p_dir.x = data->p_dir.x * cos(-rotation_speed) - data->p_dir.y
		* sin(-rotation_speed);
	data->p_dir.y = old_dir_x * sin(-rotation_speed) + data->p_dir.y
		* cos(-rotation_speed);
	old_plane_x = data->cam_plane.x;
	data->cam_plane.x = data->cam_plane.x * cos(-rotation_speed)
		- data->cam_plane.y * sin(-rotation_speed);
	data->cam_plane.y = old_plane_x * sin(-rotation_speed) + data->cam_plane.y
		* cos(-rotation_speed);
}

void	rotate_right(t_data *data, double rotation_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->p_dir.x;
	data->p_dir.x = data->p_dir.x * cos(rotation_speed) - data->p_dir.y
		* sin(rotation_speed);
	data->p_dir.y = old_dir_x * sin(rotation_speed) + data->p_dir.y
		* cos(rotation_speed);
	old_plane_x = data->cam_plane.x;
	data->cam_plane.x = data->cam_plane.x * cos(rotation_speed)
		- data->cam_plane.y * sin(rotation_speed);
	data->cam_plane.y = old_plane_x * sin(rotation_speed) + data->cam_plane.y
		* cos(rotation_speed);
}
