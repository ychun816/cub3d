/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:07 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/27 16:11:32 by ahadj-ar         ###   ########.fr       */
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

int	count_map_rows(char **map, int x, int y)
{
	int	i_grec;

	i_grec = y;
	if (!map[i_grec][x])
		return (0);
	while (map[i_grec][x] && (map[i_grec][x] != ' ' || map[i_grec][x] != '\t'))
	{
		i_grec++;
	}
	return (i_grec);
}

void	move_forward(int keysim, t_cube *cube, t_data *data)
{
	char	**map;
	double	new_x;
	double	new_y;
	int		row_length;

	map = cube->map;
	if (keysim == XK_w)
	{
		new_x = data->p_pos.x + data->p_dir.x * MOVE_SPEED;
		new_y = data->p_pos.y + data->p_dir.y * MOVE_SPEED;
		if (new_y >= 0)
		{
			row_length = ft_strlen(map[(int)new_y]);
			if (new_x >= 0 && new_x < row_length)
			{
				if (map[(int)new_y][(int)new_x] != '1')
				{
					data->p_pos.x = new_x;
					data->p_pos.y = new_y;
				}
			}
		}
	}
	else
		return ;
}

void	move_backward(int keysim, t_cube *cube, t_data *data)
{
	char	**map;
	double	new_x;
	double	new_y;
	int		row_length;

	map = cube->map;
	if (keysim == XK_s)
	{
		new_x = data->p_pos.x - data->p_dir.x * MOVE_SPEED;
		new_y = data->p_pos.y - data->p_dir.y * MOVE_SPEED;
		if (new_y >= 0)
		{
			row_length = ft_strlen(map[(int)new_y]);
			if (new_x >= 0 && new_x < row_length)
			{
				if (map[(int)new_y][(int)new_x] != '1')
				{
					data->p_pos.x = new_x;
					data->p_pos.y = new_y;
				}
			}
		}
	}
}

int	input(int keysim, t_cube *cube)
{
	if (keysim == XK_w)
		move_forward(keysim, cube, cube->data);
	if (keysim == XK_s)
		move_backward(keysim, cube, cube->data);
	if (keysim == XK_Escape)
		return (cleanup(cube, 0), 0);
	if (keysim == XK_d)
		rotate_left(cube->data);
	if (keysim == XK_a)
		rotate_right(cube->data);
	return (0);
}

int	close_window(t_cube *cube)
{
	return (cleanup(cube, 0), 0);
}
