/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:11 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 18:09:35 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int	check_data(t_data *data)
{
	if (data->c_color && data->f_color && data->west_img && data->east_img
		&& data->north_img && data->south_img)
		return (1);
	else
		return (0);
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
			tmp = strndup_start(str, i);
			break ;
		}
		i++;
	}
	free(str);
	return (tmp);
}

int	get_textures(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->map[i])
	{
		if (check_data(cube->data))
			break ;
		if (cube->map[i][0] == 'N' && cube->map[i][1] == 'O')
			cube->data->north_img = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'S' && cube->map[i][1] == 'O')
			cube->data->south_img = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'W' && cube->map[i][1] == 'E')
			cube->data->west_img = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'E' && cube->map[i][1] == 'A')
			cube->data->east_img = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'F')
			cube->data->f_color = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'C')
			cube->data->c_color = ft_strdup(cube->map[i]);
		i++;
	}
	return (0);
}

int	get_data(t_cube *cube)
{
	get_textures(cube);
	if (!check_data(cube->data))
		return (1);
	cube->data->north_img = trim_texture(cube->data->north_img);
	cube->data->south_img = trim_texture(cube->data->south_img);
	cube->data->west_img = trim_texture(cube->data->west_img);
	cube->data->east_img = trim_texture(cube->data->east_img);
	printf("%s\n", cube->data->north_img);
	printf("%s\n", cube->data->west_img);
	printf("%s\n", cube->data->south_img);
	printf("%s\n", cube->data->east_img);
	printf("%s\n", cube->data->c_color);
	printf("%s\n", cube->data->f_color);
	return (0);
}
