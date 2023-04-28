/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:46 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/28 11:52:10 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

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

void paint_player(void)
{
	if ((eng()->keys.arr_left == 0 && eng()->keys.arr_right == 0) || (eng()->keys.arr_left == 1 && eng()->keys.arr_right == 1))
	{
		act()->walk_action = 0;
		if (act()->last_action == 0)
    		paint_icon(canvas()->player_normal_right, objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
		else if (act()->last_action == 1)
			paint_icon(canvas()->player_normal_left, objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
	}
	else
		check_movement();
	if (eng()->keys.space == 1 && !act()->falling)
		jump(0.1);
}

void paint_all()
{
	// printf("position_x: %f  ||| position_y: %f\n", objs()->player.pos_x, objs()->player.pos_y);
	// printf("char: %c\n", data()->map.map[(int)objs()->player.pos_y][(int)objs()->player.pos_x]);
	get_background();
	get_tiles();
    paint_player();
}