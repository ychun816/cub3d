/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:34:58 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/22 15:04:28 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "./cub3d.h"

typedef struct s_vec
{
	double	x;
	double	y;
}			t_vec;

typedef struct s_map
{
	int		x;
	int		y;
}			t_map;

#endif