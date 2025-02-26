/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:43:22 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/26 18:36:54 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*tab;

	total_size = nmemb * size;
	tab = malloc(total_size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[j])
	{
		ptr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	ptr[i] = '\0';
	return (ptr);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > 255 || res < 0 || ft_strlen((char *)str) > 3)
		return (-1);
	return (res * sign);
}
