/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:28:46 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 16:35:46 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_extension(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 1] != 'b' && av[i - 2] != 'u' && av[i - 3] != 'c')
		return (1);
	return (0);
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
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				j++;
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	i--;
	j = -1;
	while (map[i][++j])
	{
		if (map[i][j] != '1')
			return (1);
	}
	return (0);
}

int	parsing(char **av, t_cube *cube)
{
	if (check_extension(av[1]))
	{
		printf("Wrong map extension\n");
		return (1);
	}
	if (get_map(av[1], cube) == 1)
	{
		printf("Invalid map\n");
		return (1);
	}
	get_data(cube);
	if (check_elements(cube->map))
	{
		printf("Invalid map : wrong elements\n");
		return (1);
	}
	if (check_walls(cube->map))
	{
		printf("Invalid map : map is not closed\n");
		return (1);
	}
	return (0);
}
