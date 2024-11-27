/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:31:32 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/27 11:54:29 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_data(t_data *data)
{
	if (data->ea_img)
		free(data->ea_img);
	if (data->we_img)
		free(data->we_img);
	if (data->so_img)
		free(data->so_img);
	if (data->no_img)
		free(data->no_img);
	if (data->c_line)
		free(data->c_line);
	if (data->f_line)
		free(data->f_line);
}

void	destroy_sprites(t_cube *cube)
{
	if (cube->no_xpm)
		mlx_destroy_image(cube->mlx, cube->no_xpm);
	if (cube->so_xpm)
		mlx_destroy_image(cube->mlx, cube->so_xpm);
	if (cube->we_xpm)
		mlx_destroy_image(cube->mlx, cube->we_xpm);
	if (cube->ea_xpm)
		mlx_destroy_image(cube->mlx, cube->ea_xpm);
}

void	cleanup_mlx(t_cube *cube)
{
	if (cube->img->img)
	{
		mlx_destroy_image(cube->mlx, cube->img->img);
		cube->img->img = NULL;
	}
	if (cube->mlx_win)
	{
		mlx_destroy_window(cube->mlx, cube->mlx_win);
		cube->mlx_win = NULL;
	}
	if (cube->mlx)
	{
		mlx_destroy_display(cube->mlx);
		free(cube->mlx);
		cube->mlx = NULL;
	}
}

void	cleanup(t_cube *cube, int exit_code)
{
	if (cube->map)
		free_tab(cube->map);
	if (cube->data)
		free_data(cube->data);
	destroy_sprites(cube);
	if (cube->mlx)
		cleanup_mlx(cube);
	free(cube->img);
	exit(exit_code);
}
