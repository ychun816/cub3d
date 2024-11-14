/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:11 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/14 15:17:36 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_data(t_data *data)
{
	if (data->c_line && data->f_line && data->west_img && data->east_img
		&& data->north_img && data->south_img)
		return (0);
	else
		return (1);
}

char	*trim_texture(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		if (str[i] == '.')
		{
			tmp = ft_strndup_start(str, i);
			break ;
		}
		i++;
	}
	free(str);
	return (tmp);
}

void	copy_textures(t_cube *cube, int i, int j)
{
	if (cube->map[i][j] == 'N' && cube->map[i][j + 1] && cube->map[i][j
		+ 1] == 'O')
		cube->data->north_img = ft_strdup(cube->map[i]);
	else if (cube->map[i][j] == 'S' && cube->map[i][j + 1] && cube->map[i][j
		+ 1] == 'O')
		cube->data->south_img = ft_strdup(cube->map[i]);
	else if (cube->map[i][j] == 'W' && cube->map[i][j + 1] && cube->map[i][j
		+ 1] == 'E')
		cube->data->west_img = ft_strdup(cube->map[i]);
	else if (cube->map[i][j] == 'E' && cube->map[i][j + 1] && cube->map[i][j
		+ 1] == 'A')
		cube->data->east_img = ft_strdup(cube->map[i]);
	else if (cube->map[i][j] == 'F')
		cube->data->f_line = ft_strdup(cube->map[i]);
	else if (cube->map[i][j] == 'C')
		cube->data->c_line = ft_strdup(cube->map[i]);
}

void	get_textures(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		if (check_data(cube->data) == 0)
			break ;
		while (cube->map[i][j] && cube->map[i][j] == ' ')
			j++;
		copy_textures(cube, i, j);
		i++;
	}
}

int	get_data(t_cube *cube)
{
	get_textures(cube);
	if (check_data(cube->data))
		return (1);
	cube->data->north_img = trim_texture(cube->data->north_img);
	cube->data->south_img = trim_texture(cube->data->south_img);
	cube->data->west_img = trim_texture(cube->data->west_img);
	cube->data->east_img = trim_texture(cube->data->east_img);
	printf("%s\n", cube->data->north_img);
	printf("%s\n", cube->data->west_img);
	printf("%s\n", cube->data->south_img);
	printf("%s\n", cube->data->east_img);
	printf("%s\n", cube->data->c_line);
	printf("%s\n", cube->data->f_line);
	cube->data->c_value = get_rgb(cube->data->f_line);
	cube->data->f_value = get_rgb(cube->data->c_line);
		if (cube->data->c_value == -1 || cube->data->f_value == -1)
			return (1);
	return (0);
}
