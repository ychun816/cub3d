/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:31:23 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/26 13:22:47 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_ray(t_vec *side_dist, t_vec *step, t_vec *delta, t_data *data)
{
	if (data->ray_dir.x < 0)
	{
		step->x = -1;
		side_dist->x = (data->p_pos.x - data->map.x) * delta->x;
	}
	else
	{
		step->x = 1;
		side_dist->x = (data->map.x + 1.0 - data->p_pos.x) * delta->x;
	}
	if (data->ray_dir.y < 0)
	{
		step->y = -1;
		side_dist->y = (data->p_pos.y - data->map.y) * delta->y;
	}
	else
	{
		step->y = 1;
		side_dist->y = (data->map.y + 1.0 - data->p_pos.y) * delta->y;
	}
}

int	ray_dda(t_vec *side_dist, t_vec *delta_dist, t_vec *step, t_map *map)
{
	if (side_dist->x < side_dist->y)
	{
		side_dist->x += delta_dist->x;
		map->x += step->x;
		return (0);
	}
	else
	{
		side_dist->y += delta_dist->y;
		map->y += step->y;
		return (1);
	}
}

double	ray_distance(t_cube *cube, t_data *data, t_vec *ray_dir, int *side)
{
	t_vec	delta_dist;
	t_vec	side_dist;
	t_vec	step;

	data->map.x = (int)data->p_pos.x;
	data->map.y = (int)data->p_pos.y;
	*side = 0;
	delta_dist.x = fabs(1.0 / ray_dir->x);
	delta_dist.y = fabs(1.0 / ray_dir->y);
	get_ray(&side_dist, &step, &delta_dist, data);
	while (1)
	{
		*side = ray_dda(&side_dist, &delta_dist, &step, &data->map);
		if (cube->map[data->map.y][data->map.x] == '1')
			break ;
	}
	if (*side == 0)
		return (side_dist.x - delta_dist.x);
	else
		return (side_dist.y - delta_dist.y);
}

int	display(t_cube *cube)
{
	int		x;
	int		side;
	double	cam_x;
	double	ray_len;
	t_data	*data;

	data = cube->data;
	data->cam_plane.x = 0;
	data->cam_plane.y = 0.66;
	x = -1;
	mlx_clear_window(cube->mlx, cube->mlx_win);
	while (++x < W_WIDTH)
	{
		cam_x = 2 * x / (double)W_WIDTH - 1;
		data->ray_dir.x = data->p_dir.x + data->cam_plane.x * cam_x;
		data->ray_dir.y = data->p_dir.y + data->cam_plane.y * cam_x;
		ray_len = ray_distance(cube, data, &data->ray_dir, &side);
		walls(cube, x, ray_len);
	}
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	return (0);
}
