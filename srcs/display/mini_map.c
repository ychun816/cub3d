/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/25 16:18:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	mini_map(t_cube *cube)
{
	t_img *img;

	img = cube->img;
	int y;
	int x;

	x = 0;
	y = 0;
	mlx_clear_window(cube->mlx, cube->mlx_win);
	while (cube->map[y][x])
	{
		x = 0;
		while (x < ft_strlen(cube->map[y]))
		{
			if (cube->map[y][x] == '1')
			{
				ft_pixel_put(cube->img, x * 18, y * 18, 0xFFFFFFFF);
				mlx_put_image_to_window(cube->mlx, cube->mlx_win,
					cube->img->img, x, y);
			}
			else
			{
				ft_pixel_put(cube->img, x * 18, y * 18, 0x00696969);
				mlx_put_image_to_window(cube->mlx, cube->mlx_win,
					cube->img->img, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}