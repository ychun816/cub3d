/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:07:14 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/27 12:05:27 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_color(t_wall *wall, t_cube *cube, int *color, int tex_y)
{
	if (wall->textnum == 0)
		*color = cube->img->north[tex_y * cube->data->xpm_width + wall->text_x];
	else if (wall->textnum == 1)
		*color = cube->img->south[tex_y * cube->data->xpm_width + wall->text_x];
	else if (wall->textnum == 2)
		*color = cube->img->west[tex_y * cube->data->xpm_width + wall->text_x];
	else
		*color = cube->img->east[tex_y * cube->data->xpm_width + wall->text_x];
}

void	display_vertical_line(t_cube *cube, int x, t_wall *wall)
{
	int	color;
	int	tex_y;
	int	y;

	y = 0;
	color = 0;
	while (y < W_HEIGHT)
	{
		if (y < wall->draw_start)
			ft_pixel_put(cube->img, x, y, cube->f_value);
		else if (y > wall->draw_end)
			ft_pixel_put(cube->img, x, y, cube->c_value);
		else
		{
			tex_y = (int)wall->text_pos;
			tex_y = tex_y & (cube->data->xpm_height - 1);
			get_color(wall, cube, &color, tex_y);
			ft_pixel_put(cube->img, x, y, color);
			wall->text_pos += wall->step;
		}
		y++;
	}
}

void	get_text_pos(t_wall *wall, t_data *data)
{
	if (wall->textnum == 0)
		wall->text_x = (int)(wall->wall_x * data->xpm_width);
	else if (wall->textnum == 1)
		wall->text_x = (int)(wall->wall_x * data->xpm_width);
	else if (wall->textnum == 2)
		wall->text_x = (int)(wall->wall_x * data->xpm_width);
	else
		wall->text_x = (int)(wall->wall_x * data->xpm_width);
	wall->step = 1.0 * data->xpm_height / wall->line_height;
	wall->text_pos = (wall->draw_start - W_HEIGHT / 2 + wall->line_height / 2)
		* wall->step;
}

void	choose_textures(t_wall *wall, t_cube *cube, double ray_len)
{
	t_data	*data;

	(void)ray_len;
	data = cube->data;
	if (wall->side == 0)
	{
		if (data->ray_dir.x > 0)
			wall->textnum = 3;
		else
			wall->textnum = 2;
	}
	else
	{
		if (data->ray_dir.y > 0)
			wall->textnum = 1;
		else
			wall->textnum = 0;
	}
	get_text_pos(wall, cube->data);
}

void	walls(t_cube *cube, t_wall *wall, double ray_len)
{
	t_data	*data;
	int		x;

	data = cube->data;
	wall->line_height = (int)(W_HEIGHT / ray_len);
	wall->draw_start = -wall->line_height / 2 + W_HEIGHT / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + W_HEIGHT / 2;
	if (wall->draw_end >= W_HEIGHT)
		wall->draw_end = W_HEIGHT - 1;
	if (!wall->side)
		wall->wall_x = data->p_pos.y + ray_len * data->ray_dir.y;
	else
		wall->wall_x = data->p_pos.y + ray_len * data->ray_dir.x;
	wall->wall_x -= floor(wall->wall_x);
	if ((!wall->side && data->ray_dir.x < 0) || (wall->side == 1
			&& data->ray_dir.y < 0))
		wall->text_x = data->xpm_height - wall->text_x - 1;
	wall->step = 1.0 * data->xpm_height / wall->line_height;
	wall->text_pos = (wall->draw_start - W_HEIGHT / 2 + wall->line_height / 2
			* wall->step);
	choose_textures(wall, cube, ray_len);
	x = wall->x;
	display_vertical_line(cube, x, wall);
}
