/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:28:46 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 14:44:43 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	valid_map(char **av)
{
	char	*line;
	int		i;

	i = 0;
	while (av[1])
	{
		if (av[1][i] != 'N' || av[1][i] != 'S' || av[1][i] != 'E'
			|| av[1][i] != 'W' || av[1][i] != '1' || av[1][i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	get_map_height(char **av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (av[1][i])
	{
		if (av[1][i] == '\n')
			count++;
		i++;
	}
}

int	copy_map(char **av, t_cube *cube)
{
	int	i;
	int	count;

	i = 0;
	count = get_map_height(av);
	cube->map = ft_calloc(sizeof(char *), count + 1);
	if (!cube->map)
		return (1);
	
}

int	parsing(char **av, t_cube *cube)
{
	if (valid_map(av))
		return (1);
	if (copy_map(av, cube))
		return (1);
}
