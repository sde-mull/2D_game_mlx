/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:11 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/13 00:18:39 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void get_tiles(t_map map)
{
	int x;
	int y;
	
	y = 0;
	while (y < map.max_y)
	{
		x = 0;
		while (x < map.max_x)
		{
			if (map.map[y][x] == '2' && map.map[y - 1][x] != '2')
				paint_icon(canvas()->tile_surface, x * ICON, y * ICON, &canvas()->game);
			if (map.map[y][x] == '2' && map.map[y - 1][x] == '2')
				paint_icon(canvas()->tile_underground, x * ICON, y * ICON, &canvas()->game);
			x++;
		}
		y++;
	}
}