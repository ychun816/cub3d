/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/12 19:42:57 by ahadj-ar         ###   ########.fr       */
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
    
    // data->minimap.width = data->map.x * data->minimap.scale;
    data->minimap.width = 250;
    // data->minimap.height = data->map.y * data->minimap.scale;
    data->minimap.height = 150;

    data->minimap.offset_x = 10;
    data->minimap.offset_y = W_HEIGHT - data->minimap.height - 10;
}

//init_minimap_mlx()!!
//Creating a blank image buffer where you can draw!!
//put mini_img img -> if fail, error msg
//get mini_img addr -> if fail, error msg

int init_minimap_mlx(t_cube *cube)
{
    cube->data->mini_img.img =  mlx_new_image(cube->mlx, cube->data->minimap.width, cube->data->minimap.height);
    if (!cube->data->mini_img.img)
    {
        ft_putstr_fd("Minimap creation failed (img)\n", 2);
        return (1);
    }
    cube->data->mini_img.addr = mlx_get_data_addr(cube->data->mini_img.img, &cube->data->mini_img.bpp, &cube->data->mini_img.line_length, &cube->data->mini_img.endian);
    if (!cube->data->mini_img.addr)
    {
        ft_putstr_fd("Minimap creation failed (img addr)\n", 2);
        return (1);
    }    
    return (0);
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
    // put_minimap_frame(data);
}

//put minimap frame
//horizontal -> top + bottom
//vertical -> left + right
// void put_minimap_frame(t_data *data)
// {
//     int y;
//     int x;
    
//     //horizontal ---- ___
//     x = -1;
//     while (++x < data->minimap.width)
//     {
//         ft_pixel_put(&data->mini_img, x, 0, 0x000000);//top
//         ft_pixel_put(&data->mini_img, x, data->minimap.height - 1, 0x000000);//bottom
//     }
//     //vertical | |
//     y = -1;
//     while (++y < data->minimap.height)
//     {
//         ft_pixel_put(&data->mini_img, 0, y, 0x000000);//left
//         ft_pixel_put(&data->mini_img, data->minimap.width - 1, y, 0x000000);//right
//     }
// }

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
            screen_x = map_x *data->minimap.scale + i;//data->minimap.offset_x * (map_x *data->minimap.scale) + i
            screen_y = map_y *data->minimap.scale + j;//data->minimap.offset_y * (map_y *data->minimap.scale) + j
            ft_pixel_put(&data->mini_img, screen_x, screen_y, color);
            //t_img *pixel, int x, int y, int color
        }
    }
}

//set player pos on minimap
//get player pos
//pos *scale !! convert world coordinates to minimap coordinates!!
//draw little circle (radius 2)
void    set_player_on_minimap(t_data *data)
{
    int player_x;
    int player_y;
    int x;
    int y;

    player_x = data->p_pos.x * data->minimap.scale;
    player_y = data->p_pos.y * data->minimap.scale;
    
    //draw circle
    x = -2;
    y = -2;
    while (++y <= 2)
    {
        while (++x <= 2)
        {
            if (x * x + y * y <= 4)
                ft_pixel_put(&data->mini_img, player_x + x, player_y + y, 0xFF0000);// Red
        }
    }
}

//MAIN MINIMAP
int	minimap(t_cube *cube)
{
    if (!cube->data)// || other condition?
        return (1);
    cube->data->map.map = cube->map;
    set_minimap_content(cube->data);//set map //set map frame
    set_player_on_minimap(cube->data);
    //set player fov(TBD)
    return (0);
}



// //set player_fov
// int set_player_fov(x, y, )
// {

// }


//CLEANUP MINIMAP
// Free the minimap image (main rendering image)
//texture (if have player info later)
//wall (if have player info later) //MAYBE NO NEED?
//img, just in case
void	cleanup_minimap(t_cube *cube)
{
    // if (cube->data->mini_img.textures)
    // {
    //     free(cube->data->mini_img.textures);
    //     cube->data->mini_img.textures = NULL;
    // }
    // if (cube->data->mini_img.wall)
    // {
    //     free(cube->data->mini_img.wall);
    //     cube->data->mini_img.wall = NULL;
    // }
    if (cube->data->mini_img.img)
    {
        mlx_destroy_image(cube->mlx, cube->data->mini_img.img);
        cube->data->mini_img.img = NULL;
    }   
}
