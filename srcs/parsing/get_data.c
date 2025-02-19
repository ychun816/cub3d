/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:11 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/19 17:25:15 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_data(t_data *data)
{
	if (data->c_line && data->f_line && data->we_img && data->ea_img
		&& data->no_img && data->so_img)
		return (0);
	else
		return (1);
}

char	*trim_textures(char *str)
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
	if (!cube->data->no_img && cube->map[i][j] == 'N' && cube->map[i][j + 1]
		&& cube->map[i][j + 1] == 'O')
		cube->data->no_img = ft_strdup(cube->map[i]);
	else if (!cube->data->so_img && cube->map[i][j] == 'S' && cube->map[i][j
		+ 1] && cube->map[i][j + 1] == 'O')
		cube->data->so_img = ft_strdup(cube->map[i]);
	else if (!cube->data->we_img && cube->map[i][j] == 'W' && cube->map[i][j
		+ 1] && cube->map[i][j + 1] == 'E')
		cube->data->we_img = ft_strdup(cube->map[i]);
	else if (!cube->data->ea_img && cube->map[i][j] == 'E' && cube->map[i][j
		+ 1] && cube->map[i][j + 1] == 'A')
		cube->data->ea_img = ft_strdup(cube->map[i]);
	else if (!cube->data->f_line && cube->map[i][j] == 'F')
		cube->data->f_line = ft_strdup(cube->map[i]);
	else if (!cube->data->c_line && cube->map[i][j] == 'C')
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
