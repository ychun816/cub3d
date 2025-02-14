/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:15:09 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/14 18:54:52 by yilin            ###   ########.fr       */
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
	int	max_width;//added for mini

	i = 0;
	j = 0;
	max_width = 0;
	cube->map = ft_calloc(sizeof(char *), count_nl + 1);
	while (str[i])
	{
		len = get_line_length(str, i);
		if (len > max_width)//added for mini//
			max_width = len;
		cube->map[j] = ft_calloc(sizeof(char), len + 1);
		i = copy_line(str, cube->map[j], i);
		if (str[i] == '\n')
		{
			j++;
			i++;
		}
	}
	// cube->data->map.width = max_width;//added for mini//store width
	// printf("%d\n", max_width);
	cube->data->map.height = count_nl;//added for mini//store height
	// printf("🎃cube->data->map.height: %d\n",cube->data->map.height);//DEBUG
	// printf("🎃cube->data->map.width: %d\n", cube->data->map.width);//DEBUG
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
	if (!string || string[0] == '\0')
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
