/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:45 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/27 12:11:26 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_cube(t_cube *cube, t_data *data)
{
	cube->img = (t_img *)malloc(sizeof(t_img));
	if (!cube->img)
	{
		ft_putstr_fd("Failed to allocate memory for image\n", 2);
		cleanup(cube, 1);
	}
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
	data->xpm_height = 64;
	data->xpm_width = 64;
}

void	init_struct(t_cube *cube, t_data *data, t_img *img)
{
	(void)img;
	init_cube(cube, data);
	init_data(data);
}
