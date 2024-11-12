/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:43:22 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 14:43:47 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t total_size;
	size_t i;
	unsigned char *tab;

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
