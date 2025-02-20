/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:07:14 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/20 17:46:50 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// get the color from the selected texture based on the textures coordinates,
// casted as an int * for the minilibx 

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

// render a single vertical line for the 3D view

void	display_vertical_line(t_cube *cube, int x, t_cast *cast, double ray_len)
{
	int	color;
	int	tex_y;
	int	y;

	y = 0;
	color = 0;
	while (y < W_HEIGHT)
	{
		if (y < cast->draw_start)
		{
			// cube->f_value = apply_lighting(cube->f_value, ray_len);
			ft_pixel_put(cube->img, x, y, cube->f_value);
			// void * bg = mlx_xpm_file_to_image(cube->mlx, cube->data->no_img, &width, &height);//
			// cube->img->north = (int *)mlx_get_data_addr(cube->no_xpm, &cube->img->bpp, &cube->img->line_length, &cube->img->endian);//
		}	
		else if (y > cast->draw_end)
		{
			// cube->c_value = apply_lighting(cube->c_value, ray_len);
			ft_pixel_put(cube->img, x, y, cube->c_value);
			//cube->no_xpm = mlx_xpm_file_to_image(cube->mlx, cube->data->no_img, &width, &height);//
			//cube->img->north = (int *)mlx_get_data_addr(cube->no_xpm, &cube->img->bpp, &cube->img->line_length, &cube->img->endian);//
		}
		else
		{
			tex_y = (int)cast->text_pos;
			tex_y = tex_y & (cube->data->xpm_height - 1);
			get_color(cast, cube, &color, tex_y);
			color = apply_lighting(color, ray_len);
			ft_pixel_put(cube->img, x, y, color);
			cast->text_pos += cast->step;
		}
		y++;
	}
}

// calculates textures coordinates for walls

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

// determines which texture to use based on the wall hit direction

void	choose_textures(t_cast *cast, t_cube *cube)
{
	t_data	*data;

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

// determines the properties of the wall slice and calls textures functions

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
		cast->wall_x = data->p_pos.x + ray_len * data->ray_dir.x;
	cast->wall_x -= floor(cast->wall_x);
	if ((!cast->side && data->ray_dir.x < 0) || (cast->side == 1
			&& data->ray_dir.y < 0))
		cast->text_x = data->xpm_height - cast->text_x - 1;
	cast->step = 1.0 * data->xpm_height / cast->line_height;
	cast->text_pos = (cast->draw_start - W_HEIGHT / 2 + cast->line_height / 2
			* cast->step);
	choose_textures(cast, cube);
	x = cast->x;
	display_vertical_line(cube, x, cast, ray_len);
}
