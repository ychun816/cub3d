/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/19 17:15:24 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/** mose_move
- no move if at center
- y tronpi!! only check x -> rotate left/right
*/
int	mouse_move(int x, int y, void *arg)
{
	static int	s_x = 0;
	t_cube		*cube;

	cube = (t_cube *)arg;
	(void)y;
	if (!s_x)
		s_x = x;
	if (x < s_x)
		rotate_left(cube->data);
	if (x > s_x)
		rotate_right(cube->data);
	s_x = x;
	return (0);
}
