/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:11 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/27 16:55:17 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void get_tiles(void)
{
	int x;
	int y;
	
	y = 0;
	while (y < data()->map.max_y)
	{
		x = 0;
		while (x < data()->map.max_x)
		{
			if (data()->map.map[y][x] == '2')
				paint_icon(canvas()->tile, x * ICON, y * ICON);
			x++;
		}
		y++;
	}
}