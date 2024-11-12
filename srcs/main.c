/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:26:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 14:36:40 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_cube cube;

	if (ac != 2)
	{
		printf("Wrong arguments\n");
		return (1);
	}
	else
	{
		if (parsing(av, &cube))
		{
			printf("Wrong map\n");
			return (1);
		}
	}
}