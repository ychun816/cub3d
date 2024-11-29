/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:07 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/28 15:37:21 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_cube *cube, t_data *data)
{
	char	**map;
	double	new_x;
	double	new_y;
	int		row_length;

	map = cube->map;
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

void	move_backward(t_cube *cube, t_data *data)
{
	char	**map;
	double	new_x;
	double	new_y;
	int		row_length;

	map = cube->map;
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

void	move_left(t_cube *cube, t_data *data)
{
	char	**map;
	double	new_x;
	double	new_y;
	int		row_length;

	map = cube->map;
	new_x = data->p_pos.x + data->p_dir.y * MOVE_SPEED;
	new_y = data->p_pos.y - data->p_dir.x * MOVE_SPEED;
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

void	move_right(t_cube *cube, t_data *data)
{
	char	**map;
	double	new_x;
	double	new_y;
	int		row_length;

	map = cube->map;
	new_x = data->p_pos.x - data->p_dir.y * MOVE_SPEED;
	new_y = data->p_pos.y + data->p_dir.x * MOVE_SPEED;
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
