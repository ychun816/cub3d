/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:07 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/19 20:12:03 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_cube *cube, t_data *data)
{
	double	new_x;
	double	new_y;
	int		row_length;

	new_x = data->p_pos.x;
	new_y = data->p_pos.y;
	if (cube->map[(int)data->p_pos.y]
		[(int)(data->p_pos.x + data->p_dir.x * MOVE_SPEED)] != '1')
		new_x = data->p_pos.x + data->p_dir.x * MOVE_SPEED;
	if (cube->map[(int)(data->p_pos.y + data->p_dir.y * MOVE_SPEED)]
		[(int)data->p_pos.x] != '1')
		new_y = data->p_pos.y + data->p_dir.y * MOVE_SPEED;
	if (new_y >= 0)
	{
		row_length = ft_strlen(cube->map[(int)new_y]);
		if (new_x >= 0 && new_x < row_length)
		{
			if (cube->map[(int)new_y][(int)new_x] != '1')
			{
				data->p_pos.x = new_x;
				data->p_pos.y = new_y;
			}
		}
	}
}

void	move_backward(t_cube *cube, t_data *data)
{
	double	new_x;
	double	new_y;
	int		row_length;

	new_x = data->p_pos.x;
	new_y = data->p_pos.y;
	if (cube->map[(int)data->p_pos.y]
		[(int)(data->p_pos.x - data->p_dir.x * MOVE_SPEED)] != '1')
		new_x = data->p_pos.x - data->p_dir.x * MOVE_SPEED;
	if (cube->map[(int)(data->p_pos.y - data->p_dir.y * MOVE_SPEED)]
		[(int)data->p_pos.x] != '1')
		new_y = data->p_pos.y - data->p_dir.y * MOVE_SPEED;
	if (new_y >= 0)
	{
		row_length = ft_strlen(cube->map[(int)new_y]);
		if (new_x >= 0 && new_x < row_length)
		{
			if (cube->map[(int)new_y][(int)new_x] != '1')
			{
				data->p_pos.x = new_x;
				data->p_pos.y = new_y;
			}
		}
	}
}

void	move_left(t_cube *cube, t_data *data)
{
	double	new_x;
	double	new_y;
	int		row_length;

	new_x = data->p_pos.x;
	new_y = data->p_pos.y;
	if (cube->map[(int)data->p_pos.y]
		[(int)(data->p_pos.x + data->p_dir.y * MOVE_SPEED)] != '1')
		new_x = data->p_pos.x + data->p_dir.y * MOVE_SPEED;
	if (cube->map[(int)(data->p_pos.y - data->p_dir.x * MOVE_SPEED)]
		[(int)data->p_pos.x] != '1')
		new_y = data->p_pos.y - data->p_dir.x * MOVE_SPEED;
	if (new_y >= 0)
	{
		row_length = ft_strlen(cube->map[(int)new_y]);
		if (new_x >= 0 && new_x < row_length)
		{
			if (cube->map[(int)new_y][(int)new_x] != '1')
			{
				data->p_pos.x = new_x;
				data->p_pos.y = new_y;
			}
		}
	}
}

void	move_right(t_cube *cube, t_data *data)
{
	double	new_x;
	double	new_y;
	int		row_length;

	new_x = data->p_pos.x;
	new_y = data->p_pos.y;
	if (cube->map[(int)data->p_pos.y]
		[(int)(data->p_pos.x - data->p_dir.y * MOVE_SPEED)] != '1')
		new_x = data->p_pos.x - data->p_dir.y * MOVE_SPEED;
	if (cube->map[(int)(data->p_pos.y + data->p_dir.x * MOVE_SPEED)]
		[(int)data->p_pos.x] != '1')
		new_y = data->p_pos.y + data->p_dir.x * MOVE_SPEED;
	if (new_y >= 0)
	{
		row_length = ft_strlen(cube->map[(int)new_y]);
		if (new_x >= 0 && new_x < row_length)
		{
			if (cube->map[(int)new_y][(int)new_x] != '1')
			{
				data->p_pos.x = new_x;
				data->p_pos.y = new_y;
			}
		}
	}
}
