/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:53:46 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/27 21:08:20 by sde-mull         ###   ########.fr       */
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

void move(int x, int y)
{
	double temp;

	temp = objs()->player.pos_x + (x * 0.06);
	if (objs()->player.pos_x > 0 && objs()->player.pos_x < data()->map.max_x - 1)
		objs()->player.pos_x = temp;
	else if ((objs()->player.pos_x <= 0 && x > 0) || (objs()->player.pos_x >= data()->map.max_x - 1 && x < 0))
		objs()->player.pos_x = temp;
	if (act()->walk_action < 5)
		act()->walk_action++;
	else
		act()->walk_action = 0;
	if (x > 0)
	{
		act()->last_action = 0;
		paint_icon(canvas()->player_walk_right[act()->walk_action], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
	}
	else
	{
		act()->last_action = 1;
		paint_icon(canvas()->player_walk_left[act()->walk_action], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
	}
}

void check_movement(void)
{
	if (eng()->keys.arr_left == 1)
		move(-1, 0);
	if (eng()->keys.arr_right == 1)
		move(1, 0);
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
}

void paint_all()
{
	get_background();
	get_tiles();
    paint_player();
}