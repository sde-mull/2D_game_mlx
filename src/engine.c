/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:00:51 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/28 21:27:31 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void jump(double height)
{
    double temp;
    double temp_x;
    double relative_temp;
    int     abs_temp;

    temp = objs()->player.pos_y - height;
    relative_temp = temp - temp;
    if (relative_temp < 0.9)
        abs_temp = floor((temp));
    else
        abs_temp = ceil(relative_temp);
    if (data()->map.map[abs_temp][eng()->abs_pos_x] != '2')
        objs()->player.pos_y = temp;
    if (act()->jumping * height >= 3)
    {
        eng()->keys.space = 0;
        act()->jumping = 0;
    }
    else
        act()->jumping += 1;
}

void gravity(t_player *player, double velocity)
{
    double     temp_y;
    double     relative_position_x;

    temp_y = player->pos_y + velocity;
    relative_position_x = objs()->player.pos_x - (int)objs()->player.pos_x;
    if (relative_position_x < 0.5)
        eng()->abs_pos_x = floor((objs()->player.pos_x));
    else
        eng()->abs_pos_x = ceil(objs()->player.pos_x);
    if ((int)temp_y >= data()->map.max_y - 1)
        exit_game();
    if (data()->map.map[(int)temp_y + 1][(int)(eng()->abs_pos_x)] != '2')
    {
        player->pos_y = temp_y;
        act()->falling = 1;
    }
    else
        act()->falling = 0;
}

void move(int x, int y)
{
	double temp;
    int     flg;
    int     confirm_pos;
    double     relative_position_y;

	temp = objs()->player.pos_x + (x * 0.06);
    confirm_pos = x > 0;
    relative_position_y = objs()->player.pos_y - (int)objs()->player.pos_y;
    if (relative_position_y < 0.5)
        eng()->abs_pos_y = floor((objs()->player.pos_y));
    else
        eng()->abs_pos_y = ceil(objs()->player.pos_y);
    flg = data()->map.map[eng()->abs_pos_y][(int)temp + confirm_pos] != '2';
	if (temp > 0 && temp < data()->map.max_x - 1 && flg)
		    objs()->player.pos_x = temp;
	else if ((temp <= 0 && x > 0) || (temp >= data()->map.max_x - 1 && x < 0) && flg)
		    objs()->player.pos_x = temp;
	if (act()->walk_action < 5)
		act()->walk_action++;
	else
		act()->walk_action = 0;
	if (x > 0)
	{
		act()->last_action = 0;
        if (!act()->jumping && !act()->falling)
		    paint_icon(canvas()->player_walk_right[act()->walk_action], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
	}
	else
	{
		act()->last_action = 1;
        if (!act()->jumping && !act()->falling)
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
