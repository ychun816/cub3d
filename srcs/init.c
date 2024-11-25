/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:45 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/25 15:25:11 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	cube->img->img = mlx_new_image(cube->mlx, W_WIDTH, W_HEIGHT);
	if (!cube->img->img)
		printf("Img creation failed\n");
	cube->img->addr = mlx_get_data_addr(cube->img->img, &cube->img->bpp,
			&cube->img->line_length, &cube->img->endian);
	if (!cube->img->addr)
		printf("Img creation failed\n");
}

void	init_cube(t_cube *cube, t_data *data, t_img *img)
{
	cube->img = img;
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

void	init_struct(t_cube *cube, t_data *data, t_img *img)
{
	init_cube(cube, data, img);
	init_data(data);
}
