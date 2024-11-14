/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:15:09 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/14 14:01:01 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*read_and_concat(int fd, char *line)
{
	char	buff[BUFFER_SIZE + 1];
	int		cz;

	cz = 1;
	while (cz > 0)
	{
		cz = read(fd, buff, BUFFER_SIZE);
		if (cz < 0)
		{
			if (line)
				free(line);
			return (NULL);
		}
		buff[cz] = '\0';
		line = ft_strjoin(line, buff);
		if (!line)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_line(int fd)
{
	char	*line;

	line = ft_calloc(sizeof(char), 1);
	if (fd == -1)
		return (NULL);
	line = read_and_concat(fd, line);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	copy_line(char *str, char *map_line, int i)
{
	int	k;

	k = 0;
	while (str[i] && str[i] != '\n')
	{
		map_line[k] = str[i];
		k++;
		i++;
	}
	map_line[k] = '\0';
	return (i);
}

void	stock_map(char *str, t_cube *cube, int count_nl)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	cube->map = ft_calloc(sizeof(char *), count_nl + 1);
	while (str[i])
	{
		len = get_line_length(str, i);
		cube->map[j] = ft_calloc(sizeof(char), len + 1);
		i = copy_line(str, cube->map[j], i);
		if (str[i] == '\n')
		{
			j++;
			i++;
		}
	}
}

int	get_map(char *str, t_cube *cube)
{
	int		fd;
	int		len;
	int		count_nl;
	char	*string;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	string = get_line(fd);
	if (string[0] == '\0')
		return (free(string), close(fd), 1);
	len = 0;
	count_nl = 0;
	while (string[len])
	{
		if (string[len] == '\n')
			count_nl++;
		len++;
	}
	count_nl++;
	stock_map(string, cube, count_nl);
	free(string);
	close(fd);
	return (0);
}
