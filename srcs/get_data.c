/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:11 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 17:53:32 by ahadj-ar         ###   ########.fr       */
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
	if (data->C_color && data->F_color && data->WE_img && data->EA_img
		&& data->NO_img && data->SO_img)
		return (1);
	else
		return (0);
}

char	*trim_texture(char *str)
{
	char *tmp;
	int	i;

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
			cube->data->NO_img = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'S' && cube->map[i][1] == 'O')
			cube->data->SO_img = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'W' && cube->map[i][1] == 'E')
			cube->data->WE_img = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'E' && cube->map[i][1] == 'A')
			cube->data->EA_img = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'F')
			cube->data->F_color = ft_strdup(cube->map[i]);
		else if (cube->map[i][0] == 'C')
			cube->data->C_color = ft_strdup(cube->map[i]);
		i++;
	}
	return (0);
}

int	get_data(t_cube *cube)
{
	get_textures(cube);
	cube->data->NO_img = trim_texture(cube->data->NO_img);
	cube->data->SO_img = trim_texture(cube->data->SO_img);
	cube->data->WE_img = trim_texture(cube->data->WE_img);
	cube->data->EA_img = trim_texture(cube->data->EA_img);

	printf("%s\n", cube->data->NO_img);
	printf("%s\n", cube->data->WE_img);
	printf("%s\n", cube->data->SO_img);
	printf("%s\n", cube->data->EA_img);
	printf("%s\n", cube->data->C_color);
	printf("%s\n", cube->data->F_color);
	// print_tab(cube->map);
	return (0);
}