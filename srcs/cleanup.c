/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:31:32 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 17:27:02 by ahadj-ar         ###   ########.fr       */
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
	if (data->EA_img)
		free(data->EA_img);
	if (data->WE_img)
		free(data->WE_img);
	if (data->SO_img)
		free(data->SO_img);
	if (data->NO_img)
		free(data->NO_img);
	if (data->C_color)
		free(data->C_color);
	if (data->F_color)
		free(data->F_color);
}

void	cleanup(t_cube *cube)
{
	if (cube->map)
		free_tab(cube->map);
	if (cube->data)
		free_data(cube->data);
}
