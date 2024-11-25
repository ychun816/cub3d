/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:26:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/25 16:19:10 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start(t_cube *cube)
{
	mlx_loop_hook(cube->mlx, display, cube);
	mlx_loop_hook(cube->mlx, mini_map, cube);
	mlx_key_hook(cube->mlx_win, &input, cube);
	mlx_hook(cube->mlx_win, 17, 0, close_window, cube);
	mlx_loop(cube->mlx);
}

int	main(int ac, char **av)
{
	t_cube	cube;
	t_data	data;
	t_img	img;

	if (ac != 2)
	{
		printf("Wrong arguments\n");
		return (1);
	}
	else
	{
		init_struct(&cube, &data, &img);
		if (parsing(av, &cube))
			cleanup(&cube, 1);
		init_mlx(&cube);
		start(&cube);
	}
	cleanup(&cube, 0);
}
