/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/18 16:08:02 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/** mose_move 
- no move if at center
- y tronpi!! only check x -> rotate left/right
- @note 
- -> need to reset to center -> standard game move control & prevent mouse moving to edge!!!
*/
int mouse_move(int x, int y, void *arg)
{
    t_cube  *cube = (t_cube *)arg;
    // printf("mouse move cube: %p\n", cube);
    if (x == W_WIDTH / 2 && y == W_HEIGHT / 2)
        return (0);
    //left
    if (x < W_WIDTH / 2)
        rotate_left(cube->data);
    //right
    if (x > W_WIDTH / 2)
        rotate_right(cube->data);
    //reset to center
    mlx_mouse_move(cube->mlx, cube->mlx_win, W_WIDTH / 2, W_HEIGHT / 2);
    return (0);
}
