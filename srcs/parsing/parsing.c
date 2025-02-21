/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:28:46 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/21 17:39:40 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_extension(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 1] == 'b' && av[i - 2] == 'u' && av[i - 3] == 'c')
		return (0);
	return (1);
}

char	**trim_map(char **map)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	tmp = copy_tab(map);
	free_tab(map);
	while (tmp[++i])
	{
		if (first_char(tmp[i]))
			break ;
	}
	if (tmp[i] == NULL)
		return (free_tab(tmp), (NULL));
	j = i;
	while (tmp[j] && tmp[j][0] != '\0')
		j++;
	map = ft_calloc(sizeof(char *), (j - i) + 1);
	j = -1;
	while (tmp[i] && tmp[i][0] != '\0')
		map[++j] = ft_strdup(tmp[i++]);
	free_tab(tmp);
	return (map);
}

int	parsing(char **av, t_cube *cube)
{
	if (check_extension(av[1]))
	{
		ft_putstr_fd("Wrong map extension\n", 2);
		cleanup(cube, 1);
	}
	if (get_map(av[1], cube) == 1)
	{
		ft_putstr_fd("Invalid map\n", 2);
		cleanup(cube, 1);
	}
	get_data(cube);
	cube->map = trim_map(cube->map);
	if (cube->map == NULL)
		cleanup(cube, 1);
	if (check_map(cube))
	{
		ft_putstr_fd("Invalid map\n", 2);
		cleanup(cube, 1);
	}
	return (0);
}
