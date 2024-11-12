/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:28:46 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 15:41:23 by ahadj-ar         ###   ########.fr       */
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
	return (0);
}
