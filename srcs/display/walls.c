/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:07:14 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/26 13:29:04 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	display_vertical_line(t_cube *cube, int x, double ray_len)
{
	int	y;
	int	height;
	int	wall_height;

	height = (int)W_HEIGHT;
	wall_height = (int)(W_HEIGHT / ray_len);
	y = -1;
	while (++y < height)
	{
		if (y < (W_HEIGHT - wall_height) / 2)
			ft_pixel_put(cube->img, x, y, 0x00696969);
		else if (y > (W_HEIGHT + wall_height) / 2)
			ft_pixel_put(cube->img, x, y, 0x00696969);
		else
			ft_pixel_put(cube->img, x, y, 0x00000000);
	}
}

void	walls(t_cube *cube, int x, double ray_len)
{
	t_wall	wall;

	wall.line_height = (int)(W_HEIGHT / ray_len);
	wall.draw_start = -wall.line_height / 2 + W_HEIGHT / 2;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.draw_end = wall.line_height / 2 + W_HEIGHT / 2;
	if (wall.draw_end >= W_HEIGHT)
		wall.draw_end = W_HEIGHT - 1;
	display_vertical_line(cube, x, ray_len);
}
