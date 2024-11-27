/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:07:14 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/27 16:26:16 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_color(t_cast *cast, t_cube *cube, int *color, int tex_y)
{
	if (cast->textnum == 0)
		*color = cube->img->north[tex_y * cube->data->xpm_width + cast->text_x];
	else if (cast->textnum == 1)
		*color = cube->img->south[tex_y * cube->data->xpm_width + cast->text_x];
	else if (cast->textnum == 2)
		*color = cube->img->west[tex_y * cube->data->xpm_width + cast->text_x];
	else
		*color = cube->img->east[tex_y * cube->data->xpm_width + cast->text_x];
}

void	display_vertical_line(t_cube *cube, int x, t_cast *cast)
{
	int	color;
	int	tex_y;
	int	y;

	y = 0;
	color = 0;
	while (y < W_HEIGHT)
	{
		if (y < cast->draw_start)
			ft_pixel_put(cube->img, x, y, cube->f_value);
		else if (y > cast->draw_end)
			ft_pixel_put(cube->img, x, y, cube->c_value);
		else
		{
			tex_y = (int)cast->text_pos;
			tex_y = tex_y & (cube->data->xpm_height - 1);
			get_color(cast, cube, &color, tex_y);
			ft_pixel_put(cube->img, x, y, color);
			cast->text_pos += cast->step;
		}
		y++;
	}
}

void	get_text_pos(t_cast *cast, t_data *data)
{
	if (cast->textnum == 0)
		cast->text_x = (int)(cast->wall_x * data->xpm_width);
	else if (cast->textnum == 1)
		cast->text_x = (int)(cast->wall_x * data->xpm_width);
	else if (cast->textnum == 2)
		cast->text_x = (int)(cast->wall_x * data->xpm_width);
	else
		cast->text_x = (int)(cast->wall_x * data->xpm_width);
	cast->step = 1.0 * data->xpm_height / cast->line_height;
	cast->text_pos = (cast->draw_start - W_HEIGHT / 2 + cast->line_height / 2)
		* cast->step;
}

void	choose_textures(t_cast *cast, t_cube *cube, double ray_len)
{
	t_data	*data;

	(void)ray_len;
	data = cube->data;
	if (cast->side == 0)
	{
		if (data->ray_dir.x > 0)
			cast->textnum = 3;
		else
			cast->textnum = 2;
	}
	else
	{
		if (data->ray_dir.y > 0)
			cast->textnum = 1;
		else
			cast->textnum = 0;
	}
	get_text_pos(cast, cube->data);
}

void	walls(t_cube *cube, t_cast *cast, double ray_len)
{
	t_data	*data;
	int		x;

	data = cube->data;
	cast->line_height = (int)(W_HEIGHT / ray_len);
	cast->draw_start = -cast->line_height / 2 + W_HEIGHT / 2;
	if (cast->draw_start < 0)
		cast->draw_start = 0;
	cast->draw_end = cast->line_height / 2 + W_HEIGHT / 2;
	if (cast->draw_end >= W_HEIGHT)
		cast->draw_end = W_HEIGHT - 1;
	if (!cast->side)
		cast->wall_x = data->p_pos.y + ray_len * data->ray_dir.y;
	else
		cast->wall_x = data->p_pos.y + ray_len * data->ray_dir.x;
	cast->wall_x -= floor(cast->wall_x);
	if ((!cast->side && data->ray_dir.x < 0) || (cast->side == 1
			&& data->ray_dir.y < 0))
		cast->text_x = data->xpm_height - cast->text_x - 1;
	cast->step = 1.0 * data->xpm_height / cast->line_height;
	cast->text_pos = (cast->draw_start - W_HEIGHT / 2 + cast->line_height / 2
			* cast->step);
	choose_textures(cast, cube, ray_len);
	x = cast->x;
	display_vertical_line(cube, x, cast);
}
