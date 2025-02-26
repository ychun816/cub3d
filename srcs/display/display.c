/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:31:23 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/26 20:56:08 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// initialize raycasting variables with the player position and orientation
// determine distance and direction for DDA algo
// 0.00001 to avoid division by zero

void	get_ray(t_vec *side_dist, t_vec *step, t_vec *delta, t_data *data)
{
	if (data->ray_dir.x == 0)
		data->ray_dir.x = 0.00001;
	if (data->ray_dir.y == 0)
		data->ray_dir.y = 0.00001;
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

// DDA algo to determine if the ray moves in the x or y direction next
// return 0 if moving in X direction, 1 if Y

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

// calculate the distance from the player to the nearest wall,
// that the ray will touch
// use DDA algo to step through the grid of the map until a wall "1" is hit

double	ray_distance(t_cube *cube, t_data *data, t_vec *ray_dir, int *side)
{
	double	perp_cast_distance;
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
		perp_cast_distance = side_dist.x - delta_dist.x;
	else
		perp_cast_distance = side_dist.y - delta_dist.y;
	perp_cast_distance *= fabs(data->p_dir.x * ray_dir->x + data->p_dir.y
			* ray_dir->y);
	return (perp_cast_distance);
}

// start of the casting, casts rays in columns
// from left to right and get the walls heights

int	display(t_cube *cube)
{
	double	cam_x;
	double	ray_len;
	t_data	*data;
	t_cast	cast;

	data = cube->data;
	data->cam_plane.x = -data->p_dir.y * 0.6;
	data->cam_plane.y = data->p_dir.x * 0.6;
	cast.x = -1;
	while (++cast.x < W_WIDTH)
	{
		cam_x = 2 * cast.x / (double)W_WIDTH - 1;
		data->ray_dir.x = data->p_dir.x + data->cam_plane.x * cam_x;
		data->ray_dir.y = data->p_dir.y + data->cam_plane.y * cam_x;
		ray_len = ray_distance(cube, data, &data->ray_dir, &cast.side);
		walls(cube, &cast, ray_len);
	}
	if (minimap(cube))
		return (1);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->data->mini_img.img,
		cube->data->minimap.offset_x, cube->data->minimap.offset_y);
	return (0);
}
