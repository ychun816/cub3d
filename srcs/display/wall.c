/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:07:14 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/22 16:11:36 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	walls(double ray_len)
{
	int line_height;
	int draw_start;
	int draw_end;

	line_height = (int)W_HEIGHT / ray_len;
	draw_start = -line_height / 2 - (int)W_HEIGHT / 2;
	if (draw_end < 0)
		draw_start = 0;
	draw_end = line_height / 2 + (int)W_HEIGHT / 2;
	if (draw_end >= W_HEIGHT)
		draw_end = W_HEIGHT - 1;
}
