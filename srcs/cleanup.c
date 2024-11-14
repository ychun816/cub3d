/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:31:32 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/14 15:45:10 by ahadj-ar         ###   ########.fr       */
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
	if (data->east_img)
		free(data->east_img);
	if (data->west_img)
		free(data->west_img);
	if (data->south_img)
		free(data->south_img);
	if (data->north_img)
		free(data->north_img);
	if (data->c_line)
		free(data->c_line);
	if (data->f_line)
		free(data->f_line);
}

void	cleanup(t_cube *cube, int exit_code)
{
	if (cube->map)
		free_tab(cube->map);
	if (cube->data)
		free_data(cube->data);
	exit(exit_code);
}
