/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:46 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/08 21:50:39 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void paint_hit_box(t_box box)
{
	my_mlx_pixel_put(&canvas()->game, box.normal_x * ICON, box.normal_y * ICON, 0xFFFFFF);
	my_mlx_pixel_put(&canvas()->game, box.down_x * ICON, box.down_y * ICON, 0xFFFFFF);
	my_mlx_pixel_put(&canvas()->game, box.right_down_x * ICON, box.right_down_y * ICON, 0xFFFFFF);
	my_mlx_pixel_put(&canvas()->game, box.right_x * ICON, box.right_y * ICON, 0xFFFFFF);
}

void paint_icon(t_img img, int pos_x, int pos_y)
{
	int x;
	int y;
	unsigned int color;

	y = 0;
	while (y < img.imgy)
	{
		x = 0;
		while (x < img.imgx)
		{
			color = my_mlx_get_pixel(&img, x, y);
            if (color)
			    my_mlx_pixel_put(&canvas()->game, pos_x + x, pos_y + y, (int)color);
			x++;
		}
		y++;
	}	
}

void paint_objects(t_map map, t_canvas canvas, t_action act)
{
	int x;
	int y;
	
	y = 0;
	while (y < map.max_y)
	{
		x = 0;
		while (x < map.max_x)
		{
			if (map.map[y][x] == 'L')
				paint_icon(canvas.lava[act.lava], x * ICON, y * ICON);
			else if (map.map[y][x] == 'C')
				paint_icon(canvas.coin[act.coin], x * ICON, y * ICON);
			else if (map.map[y][x] == 'E')
				paint_icon(canvas.door[act.door], x * ICON, (y - 0.5) * ICON);
			x++;
		}
		y++;
	}
	
}

void paint()
{
	get_background();
	get_tiles(data()->map);
	paint_objects(data()->map, *canvas(), *act());
	// paint_hit_box(objs()->player.P_box);
}