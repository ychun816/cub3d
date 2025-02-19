/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:40:46 by yilin             #+#    #+#             */
/*   Updated: 2025/02/19 17:42:35 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_minimap_width(char **map, int len, int i, t_data *data)
{
	if (ft_strlen(map[i]) > len)
		data->map.width = ft_strlen(map[i]);
	else
		data->map.width = len;
}

/** INIT_MINIMAP
 * - linked to the game data
 * - Get actual map dimensions -> determine max width/length
 * - set scale (2 pixel per tile ensure visuality)
 * - set width/heigth-> big map x/y * scale
 */
void	init_minimap(t_cube *cube)
{
	int	max_dimension;

	if (!cube || !cube->data || !cube->data->map.map)
		return ;
	cube->data->map.height = 0;
	while (cube->data->map.map[cube->data->map.height])
		cube->data->map.height++;
	max_dimension = cube->data->map.width;
	if (cube->data->map.height > cube->data->map.width)
		max_dimension = cube->data->map.height;
	cube->data->minimap.scale = MINIMAP_SIZE / max_dimension;
	if (cube->data->minimap.scale < 2)
		cube->data->minimap.scale = 2;
	cube->data->minimap.mn_width = cube->data->map.width
		* cube->data->minimap.scale;
	cube->data->minimap.mn_height = cube->data->map.height
		* cube->data->minimap.scale;
	cube->data->minimap.offset_x = 10;
	cube->data->minimap.offset_y = W_HEIGHT - cube->data->minimap.mn_height
		- 10;
}

/** INIT_MINIMAP_MLX
 * -Creating a blank image buffer where you can draw!!
 * - put mini_img img -> if fail, error msg
 * - get mini_img addr -> if fail, error msg
 */
int	init_minimap_mlx(t_cube *cube)
{
	cube->data->mini_img.img = mlx_new_image(cube->mlx,
			cube->data->minimap.mn_width, cube->data->minimap.mn_height);
	if (!cube->data->mini_img.img)
	{
		ft_putstr_fd("Minimap creation failed (img)\n", 2);
		return (1);
	}
	cube->data->mini_img.addr = mlx_get_data_addr(cube->data->mini_img.img,
			&cube->data->mini_img.bpp, &cube->data->mini_img.line_length,
			&cube->data->mini_img.endian);
	if (!cube->data->mini_img.addr)
	{
		ft_putstr_fd("Minimap creation failed (img addr)\n", 2);
		return (1);
	}
	return (0);
}
