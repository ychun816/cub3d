/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:27:59 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/27 11:57:53 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_textures(t_cube *cube)
{
	int	width;
	int	height;

	cube->no_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->no_img, &width,
			&height);
	cube->so_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->so_img, &width,
			&height);
	cube->we_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->we_img, &width,
			&height);
	cube->ea_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->ea_img, &width,
			&height);
	if (!cube->no_xpm || !cube->so_xpm || !cube->we_xpm || !cube->ea_xpm)
	{
		ft_putstr_fd("Texture loading failed\n", 2);
		cleanup(cube, 1);
	}
	cube->img->north = (int *)mlx_get_data_addr(cube->no_xpm, &cube->img->bpp,
			&cube->img->line_length, &cube->img->endian);
	cube->img->south = (int *)mlx_get_data_addr(cube->so_xpm, &cube->img->bpp,
			&cube->img->line_length, &cube->img->endian);
	cube->img->west = (int *)mlx_get_data_addr(cube->we_xpm, &cube->img->bpp,
			&cube->img->line_length, &cube->img->endian);
	cube->img->east = (int *)mlx_get_data_addr(cube->ea_xpm, &cube->img->bpp,
			&cube->img->line_length, &cube->img->endian);
}

void	init_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
	{
		ft_putstr_fd("Window creation failed\n", 2);
		cleanup(cube, 1);
	}
	load_textures(cube);
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
