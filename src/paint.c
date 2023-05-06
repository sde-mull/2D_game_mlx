/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:46 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/06 00:43:34 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void paint_hit_box(t_box box)
{
	my_mlx_pixel_put(&canvas()->game, box.normal_x * 32, box.normal_y * 32, 0xFFFFFF);
	my_mlx_pixel_put(&canvas()->game, box.down_x * 32, box.down_y * 32, 0xFFFFFF);
	my_mlx_pixel_put(&canvas()->game, box.right_down_x * 32, box.right_down_y * 32, 0xFFFFFF);
	my_mlx_pixel_put(&canvas()->game, box.right_x * 32, box.right_y * 32, 0xFFFFFF);
}

int check_walls(t_box box)
{
	char **map;
	
	map = data()->map.map;
	if (map[(int)box.normal_y][(int)(box.normal_x - 0.1)] != '2' && map[(int)(box.down_y)][(int)(box.down_x - 0.1)] != '2'&& \
		map[(int)(box.right_down_y)][(int)(box.right_down_x + 0.1)] != '2' && map[(int)(box.right_y)][(int)(box.right_x + 0.1)] != '2' &&\
		box.normal_x > 0  && box.right_x < data()->map.max_x && box.normal_y > 0 && box.right_y > 0)
			return (1);
	return (0);
}

void paint_icon(t_img img, int pos_x, int pos_y)
{
	int x;
	int y;
	unsigned int color;

	y = 0;
	while (y < ICON)
	{
		x = 0;
		while (x < ICON)
		{
			color = my_mlx_get_pixel(&img, x, y);
            if (color)
			    my_mlx_pixel_put(&canvas()->game, pos_x + x, pos_y + y, (int)color);
			x++;
		}
		y++;
	}	
}

void paint_lava()
{
	int x;
	int y;
	static int count;
	
	y = 0;
	while (y < data()->map.max_y)
	{
		x = 0;
		while (x < data()->map.max_x)
		{
			if (data()->map.map[y][x] == 'L')
				paint_icon(canvas()->lava[act()->lava], x * ICON, y * ICON);
			x++;
		}
		y++;
	}
	count++;
	if (count == 75)
	{
		act()->lava++;
		count = 0;
	}
	if (act()->lava == 3)
		act()->lava = 0;
}

void paint_all()
{
	get_background();
	get_tiles();
	paint_lava();
	check_movement();
	check_action();
}