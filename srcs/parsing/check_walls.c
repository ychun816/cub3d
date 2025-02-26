/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:33:15 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/26 20:43:51 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_data(t_data *data)
{
	if (data->c_line && data->f_line && data->we_img && data->ea_img
		&& data->no_img && data->so_img)
		return (0);
	else
		return (1);
}

int	check_tb_walls(char *wall, int direction)
{
	int	i;

	i = 0;
	while (wall[i])
	{
		if (wall[i] != '1' && wall[i] != ' ')
		{
			if (direction == 1)
				ft_putstr_fd("North wall is incorrect\n", 2);
			else
				ft_putstr_fd("South wall is incorrect\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_lr_walls(char *wall, int direction)
{
	int	i;

	if (direction == 1)
	{
		while (*wall && *wall == ' ')
			wall++;
		if (*wall && *wall != '1')
		{
			ft_putstr_fd("West wall is incorrect\n", 2);
			return (1);
		}
		else
			return (0);
	}
	i = ft_strlen(wall) - 1;
	while (i >= 0 && wall[i] && wall[i] == ' ')
		i--;
	if (i >= 0 && wall[i] && wall[i] != '1')
	{
		ft_putstr_fd("East wall is incorrect\n", 2);
		return (1);
	}
	else
		return (0);
}

int	check_walls(char **map)
{
	int	i;

	i = 1;
	if (check_tb_walls(map[0], 1))
		return (1);
	if (check_tb_walls(map[ft_tablen(map) - 1], 2))
		return (1);
	while (map[i])
	{
		if (check_lr_walls(map[i], 2))
			return (1);
		if (check_lr_walls(map[i], 1))
			return (1);
		i++;
	}
	return (0);
}
