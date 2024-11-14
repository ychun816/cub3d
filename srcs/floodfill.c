/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:38:46 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/14 18:37:08 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	floodfill(char **map, int x, int y)
{
	if (x < 0 || x > ft_strlen(map[y]) || y < 0)
	{
		printf("pb2 == %c\n", map[y][x]);
		return (-1);
	}
	// if (map[y][x] != 'N' || map[y][x] != 'W' || map[y][x] != 'E'
	// 	|| map[y][x] != 'S' || map[y][x] != '0' || map[y][x] != '1' || map[y][x] != 'X')
	// {
	// 	printf("pb2 %c\n", map[y][x]);
	// 	return (-1);
	// }
	map[y][x] = 'X';
	print_tab(map);
	if (floodfill(map, x + 1, y) == 0 || floodfill(map, x - 1, y) == 0
		|| floodfill(map, x, y + 1) == 0 || floodfill(map, x, y - 1) == 0)
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
	res = floodfill(copy_map, data->x_pos, data->y_pos);
	if (res == -1)
	{
		ft_putstr_fd("Map is not possible\n", 2);
		return (1);
	}
	free_tab(copy_map);
	return (0);
}
