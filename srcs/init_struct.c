/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:45 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/18 16:40:23 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_cube(t_cube *cube, t_data *data)
{
	cube->map = NULL;
	cube->mlx = NULL;
	cube->mlx_win = NULL;
	cube->data = data;
}

void	init_data(t_data *data)
{
	data->east_img = NULL;
	data->north_img = NULL;
	data->west_img = NULL;
	data->south_img = NULL;
	data->f_line = NULL;
	data->c_line = NULL;
	data->c_value = 0;
	data->f_value = 0;
	data->x_pos = 0;
	data->y_pos = 0;
}
