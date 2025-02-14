/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:01:49 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/14 19:05:58 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_players(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!valid_elements(map[i][j]))
			{
				ft_putstr_fd("Invalid elements in the map\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	get_player_orientation(t_vec *dir, int x, int y, char **map)
{
	if (map[y][x] == 'N')
	{
		dir->x = 1;
		dir->y = 0;
		dir->direction = NORTH;
	}
	if (map[y][x] == 'S')
	{
		dir->x = -1;
		dir->y = 0;
		dir->direction = SOUTH;
	}
	if (map[y][x] == 'W')
	{
		dir->x = -1;
		dir->y = 0;
		dir->direction = WEST;
	}
	if (map[y][x] == 'E')
	{
		dir->x = 1;
		dir->y = 0;
		dir->direction = EAST;
	}
}

void	get_player_pos(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	int len;
	len = 0;
	while (map[i])
	{
		j = 0;
		len = ft_strlen(map[i]);
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				data->p_pos.x = (double)j;
				data->p_pos.y = (double)i;
				get_player_orientation(&data->p_dir, j, i, map);
				return ;
			}
			j++;
		}
		i++;
		if (ft_strlen(map[i]) > len)
			data->map.width = ft_strlen(map[i]);
	}
	
}

int	check_map(t_cube *cube)
{
	int	player;

	player = 0;
	if (check_elements(cube->map))
		cleanup(cube, 1);
	player += count_players(cube->map, 'N');
	player += count_players(cube->map, 'S');
	player += count_players(cube->map, 'W');
	player += count_players(cube->map, 'E');
	if (player != 1)
	{
		ft_putstr_fd("No player or wrong number of player\n", 2);
		cleanup(cube, 1);
	}
	if (check_walls(cube->map))
		cleanup(cube, 1);
	get_player_pos(cube->map, cube->data);
	if (floodcall(cube->map, cube->data))
		cleanup(cube, 1);
	return (0);
}
