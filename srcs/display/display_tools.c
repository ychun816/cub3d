/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:43:07 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/19 17:31:30 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	input(int keysim, t_cube *cube)
{
	if (keysim == XK_Escape)
		return (cleanup(cube, 0), 0);
	return (0);
}

int	close_window(t_cube *cube)
{
	return (cleanup(cube, 0), 0);
}
