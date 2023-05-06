/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:00:51 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/06 00:43:04 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void jump(double height, t_player *player)
{
	t_player temp;

	temp = *player;
	temp.pos_y = temp.pos_y - height;
	get_hit_box(&temp);
	if (check_walls(temp.P_box) && act()->jumping * height < 3)
	{
		objs()->player = temp;
		act()->jumping += 1;
	}
	else
	{
		eng()->keys.space = 0;
		act()->jumping = 0;
	}
}

void gravity(t_player *player, double velocity)
{
	t_player temp;

	temp = *player;
	temp.pos_y = temp.pos_y + velocity;
	get_hit_box(&temp);
	if (check_walls(temp.P_box))
	{
		if (temp.P_box.right_down_y >= data()->map.max_y - 0.1 || \
			temp.P_box.down_y >= data()->map.max_y - 0.1 || \
			data()->map.map[(int)temp.P_box.down_y][(int)temp.P_box.down_x] == 'L' && \
			data()->map.map[(int)temp.P_box.right_down_y][(int)temp.P_box.right_down_x] == 'L')
				exit_game();
		objs()->player = temp;
		act()->falling = 1;
	}
	else
		act()->falling = 0;
}

void move(int x, int y, t_player *player)
{
	t_player temp;

	
	temp = *player;
	temp.pos_x = temp.pos_x + (x * 0.06);
	get_hit_box(&temp);
	if (check_walls(temp.P_box))
	{
		objs()->player = temp;
		act()->hit_wall = 0;
	}
	if (act()->walk_action < 5)
		act()->walk_action++;
	else
		act()->walk_action = 0;
	if (x > 0)
		act()->last_action = 0;
	else
		act()->last_action = 1;
}

void check_movement(void)
{
	if (eng()->keys.arr_left == 1)
		move(-1, 0, &objs()->player);
	if (eng()->keys.arr_right == 1)
		move(1, 0, &objs()->player);
}
