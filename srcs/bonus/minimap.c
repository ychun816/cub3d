/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/19 17:42:52 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/** SET_MINIMAP_CONTENT
 *  // Ensure row exists// Handle missing row
 * - set minimap content
 * - loop x/y -> put pixel color
 * - loop y then x -> top-bottom then left-right
 * - wall(1) , path(0)
 */
void	set_minimap_content(t_data *data)
{
	int	x;
	int	y;

	if (!data || !data->map.map)
		return ;
	y = -1;
	while (++y < data->map.height)
	{
		if (!data->map.map[y])
			return ;
		x = -1;
		while (++x < data->map.width)
		{
			if (x > (int)strlen(data->map.map[y]))
				put_minimap_pixel(data, x, y, 0x2f6299);
			else if (data->map.map[y][x] == '1')
				put_minimap_pixel(data, x, y, 0x2f6299);
			else if ((data->map.map[y][x] == '0' || data->map.map[y][x] == 'S'
					|| data->map.map[y][x] == 'W' || data->map.map[y][x] == 'E'
					|| data->map.map[y][x] == 'N'))
				put_minimap_pixel(data, x, y, 0xebb88f);
			else
				put_minimap_pixel(data, x, y, 0x002f6299);
		}
	}
}

/** PUT_MINMAP_PIXEL
 * - put pixel color
 * @note Add bounds checking
 */
void	put_minimap_pixel(t_data *data, int map_x, int map_y, int color)
{
	int	i;
	int	j;
	int	screen_x;
	int	screen_y;

	i = -1;
	while (++i < data->minimap.scale)
	{
		j = -1;
		while (++j < data->minimap.scale)
		{
			screen_x = map_x * data->minimap.scale + i;
			screen_y = map_y * data->minimap.scale + j;
			if (screen_x >= 0 && screen_x < data->minimap.mn_width
				&& screen_y >= 0 && screen_y < data->minimap.mn_height)
			{
				ft_pixel_put(&data->mini_img, screen_x, screen_y, color);
			}
		}
	}
}

/** SET PLAYER ON MINIMAP
 * - get player pos
 * @note pos *scale !!
 * -> convert world coordinates to minimap coordinates!!
 * @note draw little circle (radius 3)
 * @note Boundary check before drawing the pixel
 */
void	set_player_on_minimap(t_data *data)
{
	int	player_x;
	int	player_y;
	int	x;
	int	y;

	player_x = data->p_pos.x * data->minimap.scale;
	player_y = data->p_pos.y * data->minimap.scale;
	y = -4;
	while (y <= 4)
	{
		x = -4;
		while (x <= 4)
		{
			if (x * x + y * y <= 16)
			{
				if (player_x + x >= 0 && player_x + x < data->minimap.mn_width
					&& player_y + y >= 0 && player_y
					+ y < data->minimap.mn_height)
					ft_pixel_put(&data->mini_img, player_x + x, player_y + y,
						0xFF0000);
			}
			x++;
		}
		y++;
	}
}

/** MAIN MINIMAP*/
int	minimap(t_cube *cube)
{
	if (!cube->data || !cube->data->map.map || !cube->data->mini_img.img)
		return (1);
	set_minimap_content(cube->data);
	set_player_on_minimap(cube->data);
	return (0);
}

/* CLEANUP MINIMAP
// Free the minimap image (main rendering image)
//texture (if have player info later)
//wall (if have player info later) //MAYBE NO NEED?
//img, just in case
*/
void	cleanup_minimap(t_cube *cube)
{
	if (!cube || !cube->data)
		return ;
	if (cube->data && cube->data->mini_img.img)
	{
		mlx_destroy_image(cube->mlx, cube->data->mini_img.img);
		cube->data->mini_img.img = NULL;
	}
}
	// if (cube->data->mini_img.textures)
	// {
	//     free(cube->data->mini_img.textures);
	//     cube->data->mini_img.textures = NULL;
	// }
	// if (cube->data->mini_img.wall)
	// {
	//     free(cube->data->mini_img.wall);
	//     cube->data->mini_img.wall = NULL;
	// }