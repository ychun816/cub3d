/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/19 16:53:10 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/** mose_move
- no move if at center
- y tronpi!! only check x -> rotate left/right
- @note
- -> need to reset to center
	-> standard game move control & prevent mouse moving to edge!!!
*/
int	mouse_move(int x, int y, void *arg)
{
    static int s_x = 0;

	t_cube	*cube;
    
	cube = (t_cube *)arg;
    (void)y;

    if (!s_x)
        s_x = x;
	// left
    if (x < s_x)
		rotate_left(cube->data);
    if (x > s_x)
		rotate_right(cube->data);
	// if (x < W_WIDTH / 2)
	// 	rotate_left(cube->data);
	// // right
	// if (x > W_WIDTH / 2)
	// 	rotate_right(cube->data);
	// reset to center
    s_x = x;
	return (0);
}
