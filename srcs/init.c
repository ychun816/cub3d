/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:45 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/23 13:19:21 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_assets(t_cube *cube)
{
	cube->so_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->so_img,
			&cube->data->xpm_width, &cube->data->xpm_height);
	cube->no_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->no_img,
			&cube->data->xpm_width, &cube->data->xpm_height);
	cube->ea_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->ea_img,
			&cube->data->xpm_width, &cube->data->xpm_height);
	cube->we_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->we_img,
			&cube->data->xpm_width, &cube->data->xpm_height);
	if (!cube->so_xpm || !cube->no_xpm || !cube->we_xpm || !cube->ea_xpm)
	{
		ft_putstr_fd("loading textures error\n", 2);
		cleanup(cube, 1);
	}
}

void	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
	{
		ft_putstr_fd("Window creation failed\n", 2);
		cleanup(cube, 1);
	}
	cube->mlx_win = mlx_new_window(cube->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	if (!cube->mlx_win)
	{
		ft_putstr_fd("Window creation failed\n", 2);
		cleanup(cube, 1);
	}
	init_assets(cube);
}

void	init_cube(t_cube *cube, t_data *data)
{
	cube->map = NULL;
	cube->mlx = NULL;
	cube->mlx_win = NULL;
	cube->no_xpm = NULL;
	cube->we_xpm = NULL;
	cube->so_xpm = NULL;
	cube->ea_xpm = NULL;
	cube->c_value = 0;
	cube->f_value = 0;
	cube->data = data;
}

void	init_data(t_data *data)
{
	data->ea_img = NULL;
	data->no_img = NULL;
	data->we_img = NULL;
	data->so_img = NULL;
	data->f_line = NULL;
	data->c_line = NULL;
	data->xpm_height = 128;
	data->xpm_width = 128;
}

void	init_struct(t_cube *cube, t_data *data)
{
	init_cube(cube, data);
	init_data(data);
}
