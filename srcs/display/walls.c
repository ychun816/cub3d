/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:07:14 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/23 13:48:55 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void draw_ceiling_floor(t_cube *cube, int draw_start, int draw_end)
{
    int x, y;

    y = 0;
    while (y < draw_start)
    {
        x = 0;
        while (x < W_WIDTH)
        {
            mlx_pixel_put(cube->mlx, cube->mlx_win, x, y, cube->c_value);
            x++;
        }
        y++;
    }

    y = draw_end;
    while (y < W_HEIGHT)
    {
        x = 0;
        while (x < W_WIDTH)
        {
            mlx_pixel_put(cube->mlx, cube->mlx_win, x, y, cube->f_value);
            x++;
        }
        y++;
    }
}


void	draw_vertical_line(t_cube *cube, int x, int start, int end)
{
	int	y;
	int	color;

	color = 0x00FF0000;
	y = start;
	while (y <= end)
	{
		mlx_pixel_put(cube->mlx, cube->mlx_win, x, y, color);
		y++;
	}
}

void walls(t_cube *cube, int x, double ray_len)
{
    int line_height;
    int draw_start;
    int draw_end;

    line_height = (int)(W_HEIGHT / ray_len); 
    draw_start = -line_height / 2 + W_HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;
    draw_end = line_height / 2 + W_HEIGHT / 2;
    if (draw_end >= W_HEIGHT)
        draw_end = W_HEIGHT - 1;
    draw_vertical_line(cube, x, draw_start, draw_end);
}


