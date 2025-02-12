/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:26:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/12 19:19:10 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	input(int keysim, t_cube *cube)
{
	if (keysim == XK_w)
		move_forward(cube, cube->data);
	if (keysim == XK_s)
		move_backward(cube, cube->data);
	if (keysim == XK_a)
		move_left(cube, cube->data);
	if (keysim == XK_d)
		move_right(cube, cube->data);
	if (keysim == XK_Left)
		rotate_left(cube->data);
	if (keysim == XK_Right)
		rotate_right(cube->data);
	if (keysim == XK_Escape)
		return (cleanup(cube, 0), 0);
	return (0);
}

void	game_start(t_cube *cube)
{
	mlx_loop_hook(cube->mlx, display, cube);
	// put chun minimap in a hook // MAYBE NOT ????
	mlx_hook(cube->mlx_win, KeyPress, KeyPressMask, &input, cube);
	mlx_hook(cube->mlx_win, 17, 0, cleanup, cube);
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
		game_start(&cube);
	}
	cleanup(&cube, 0);
}