/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:03:29 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/20 20:43:50 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_pixel_put(t_img *pixel, int x, int y, int color)
{
	char	*pxl;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	pxl = pixel->addr + (y * pixel->line_length + x * (pixel->bpp / 8));
	*(unsigned int *)pxl = color;
}

int	apply_lighting(int color, double distance)
{
	int		r;
	int		g;
	int		b;
	double	intensity;
	double	max_distance;

	max_distance = 10.0;
	intensity = 1.0 - (distance / max_distance);
	if (intensity < 0.1)
		intensity = 0.1;
	r = ((color >> 16) & 0xFF) * intensity;
	g = ((color >> 8) & 0xFF) * intensity;
	b = (color & 0xFF) * intensity;
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}
