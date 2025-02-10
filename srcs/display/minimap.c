/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/10 19:37:54 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// linked to the game data
// determine max width/length
// set scale (2 pixel per tile ensure visuality)
// set width/heigth-> big map x/y * scale
void	init_minimap(t_data *data)
{
    int max_dimension;

    max_dimension = data->map.x;
    if (data->map.y > data->map.x)
        max_dimension = data->map.y;

    data->minimap.scale =  MINIMAP_SIZE / max_dimension;
    if (data->minimap.scale < 2)
        data->minimap.scale = 2;
    
    data->minimap.width = data->map.x * data->minimap.scale;
    data->minimap.height = data->map.y * data->minimap.scale;

    data->minimap.offset_x = 10;
    data->minimap.offset_y = W_HEIGHT - data->minimap.height - 10;
    	// printf("👹 INSIDE INIT MINIMAP???\n");
}

//set minimap content
//loop x/y -> put pixel color
//loop y then x -> top-bottom then left-right
// wall(1) , path(0)
void    set_minimap_content(t_data *data)
{
    int x;
    int y;

    y = -1;
    while (++y < data->map.y)
    {
        x = -1;
        while (++x < data->map.x)
        {
            if (data->map.map[y][x] == '1')//wall
                put_minimap_pixel(data, x, y, 0x2f6299); //blue 
            else if (data->map.map[y][x] == '0')//path
                put_minimap_pixel(data, x, y, 0xebb88f); //yellow
        }
    }
    //put_minimap_bg() or border
}

//put pixel color
void put_minimap_pixel(t_data *data, int map_x, int map_y, int color)
{
    int i;
    int j;
    int screen_x;
    int screen_y;

    i = -1;
    while (++i < data->minimap.scale)
    {
        j = -1;
        while (++j < data->minimap.scale)
        {
            screen_x = data->minimap.offset_x * (map_x *data->minimap.scale) + i;
            screen_y = data->minimap.offset_y * (map_y *data->minimap.scale) + j;
            ft_pixel_put(&data->mini_img, screen_x, screen_y, color);
            //t_img *pixel, int x, int y, int color
        }
    }
}

//MAIN MINIMAP
int	minimap(t_cube *cube)
{
    if (!cube->data)// || other condition?
        return (1);
    // init_minimap(cube->data);
    set_minimap_content(cube->data);
    return (0);
}


////////////////////////////////////////////////
//put minimap bg or border -> TBD
// void put_minimap_bg(t_data *data, int map_x, int map_y, int color)
// {
    
// }


// //set player pos on minimap
// int	set_player_on_minimap(t_data *data, int x, int y, int color)
// {
    
// }
// //player_fov
// int set_player_fov(x, y, )
// {

// }



//CLEANUP MINIMAP
// Free the minimap image (main rendering image)
void	cleanup_minimap(t_cube *cube)
{
    //texture (if have player info later)
    if (cube->data->mini_img.textures)
    {
        free(cube->data->mini_img.textures);
        cube->data->mini_img.textures = NULL;
    }
    //wall (if have player info later) //MAYBE NO NEED?
    if (cube->data->mini_img.wall)
    {
        free(cube->data->mini_img.wall);
        cube->data->mini_img.wall = NULL;
    }
    //img
    if (cube->data->mini_img.img)
    {
        mlx_destroy_image(cube->mlx, cube->data->mini_img.img);
        cube->data->mini_img.img = NULL;
    }   
}