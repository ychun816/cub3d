/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:11 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 16:34:33 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_tab(char **tab)
{
	int	i;
	i=0;

	while (tab[i])
	{
		printf("tab[%d] == %s\n", i, tab[i]);
		i++;
	}
}

void	get_data(t_cube *cube)
{
	print_tab(cube->map);
}