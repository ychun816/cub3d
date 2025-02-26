/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:11 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/26 21:39:21 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ko_data(t_cube *cube)
{
	printf("wrong elements in the map\n");
	cleanup(cube, 1);
}

void	copy_textures2(t_cube *cube, int i, int j)
{
	if (cube->map[i][j] == 'E' && cube->map[i][j
		+ 1] && cube->map[i][j + 1] == 'A')
	{
		if (cube->data->ea_img != NULL)
			ko_data(cube);
		cube->data->ea_img = ft_strdup(cube->map[i]);
		return ;
	}
	else if (cube->map[i][j] == 'F')
	{
		if (cube->data->f_line)
			ko_data(cube);
		cube->data->f_line = ft_strdup(cube->map[i]);
		return ;
	}
	else if (cube->map[i][j] == 'C')
	{
		if (cube->data->c_line)
			ko_data(cube);
		cube->data->c_line = ft_strdup(cube->map[i]);
		return ;
	}
	else if (cube->map[i][j] && (cube->map[i][j] != ' ' || cube->map[i][j] != '\t' 
		|| cube->map[i][j] != '\n' || cube->map[i][j] != '1' 
		|| cube->map[i][j] != '0'))
	{
		printf("test === %s\n", cube->map[i]);
		ko_data(cube);
	}
}

void	copy_textures(t_cube *cube, int i, int j)
{
	if (cube->map[i][j] == 'N' && cube->map[i][j + 1]
		&& cube->map[i][j + 1] == 'O')
	{
		if (cube->data->no_img != NULL)
			ko_data(cube);
		cube->data->no_img = ft_strdup(cube->map[i]);
		return ;	
	}
	else if (cube->map[i][j] == 'S' && cube->map[i][j
		+ 1] && cube->map[i][j + 1] == 'O')
	{
		if (cube->data->so_img != NULL)
			ko_data(cube);
		cube->data->so_img = ft_strdup(cube->map[i]);
		return ;
	}
	else if (cube->map[i][j] == 'W' && cube->map[i][j
		+ 1] && cube->map[i][j + 1] == 'E')
	{
		if (cube->data->we_img != NULL)
			ko_data(cube);
		cube->data->we_img = ft_strdup(cube->map[i]);
		return ;
	}
	copy_textures2(cube, i, j);
}

void	get_textures(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		// if (check_data(cube->data) == 0)
		// 	break ;
		while (cube->map[i][j] && (cube->map[i][j] == ' ' || cube->map[i][j] == '\t'))
			j++;
		copy_textures(cube, i, j);
		i++;
	}
}

//IT SHOULD BE OK EVEN IF THERE IS SPACE AFTER THE .XPM
void	get_data(t_cube *cube)
{
	get_textures(cube);
	if (check_data(cube->data))
	{
		printf("Incorrect XPM or RGB values\n");
		cleanup(cube, 1);
	}
	cube->data->no_img = trim_textures(cube->data->no_img);
	cube->data->so_img = trim_textures(cube->data->so_img);
	cube->data->we_img = trim_textures(cube->data->we_img);
	cube->data->ea_img = trim_textures(cube->data->ea_img);
	cube->c_value = get_rgb(cube->data->f_line);
	cube->f_value = get_rgb(cube->data->c_line);
	if (cube->c_value == -1 || cube->f_value == -1)
		cleanup(cube, 1);
}
