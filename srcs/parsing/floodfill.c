/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:38:46 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/28 13:40:08 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	floodfill(char **map, int x, int y)
{
	if (y > ft_tablen(map) || !map[y] || x < 0 || x > ft_strlen(map[y])
		|| y < 0)
		return (-1);
	if (map[y][x] && map[y][x] == ' ')
		return (-1);
	if (map[y][x] && (map[y][x] == 'X' || map[y][x] == '1'))
		return (0);
	if (map[y][x] && map[y][x] == '0')
		map[y][x] = 'X';
	if ((map[y][x + 1] && map[y + 1] && floodfill(map, x + 1, y) == 0)
			&& (map[y][x - 1] && floodfill(map, x - 1, y) == 0)
			&& (map[y + 1][x] && floodfill(map, x, y + 1) == 0)
			&& (map[y - 1][x] && floodfill(map, x, y - 1) == 0))
		return (0);
	else
		return (-1);
	return (0);
}

int	floodcall(char **map, t_data *data)
{
	int		res;
	char	**copy_map;

	res = 0;
	copy_map = copy_tab(map);
	if (!copy_map)
		return (1);
	res = floodfill(copy_map, (int)data->p_pos.x, (int)data->p_pos.y);
	if (res == -1)
	{
		free_tab(copy_map);
		ft_putstr_fd("Map is not possible\n", 2);
		return (1);
	}
	free_tab(copy_map);
	copy_map = NULL;
	return (0);
}
