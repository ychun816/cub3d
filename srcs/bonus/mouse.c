/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:59:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/21 16:15:58 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/** mose_move
- no move if at center
- y tant pis!! only check x -> rotate left/right
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
		rotate_left(cube->data, MOUSE_SPEED);
	if (x > s_x)
		rotate_right(cube->data, MOUSE_SPEED);
	s_x = x;
	return (0);
}
