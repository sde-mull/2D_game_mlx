/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:00:51 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/08 22:51:46 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void engine(void)
{
	get_fps();
	if (eng()->keys.space == 1 && !act()->falling)
		jump(0.06, &objs()->player);
	if (!act()->jumping)
		gravity(&objs()->player, 0.06, data()->map);
	check_movement(&objs()->player);
	collectible(data()->map, objs()->player.P_box);
	recenter_camera(objs()->player);
}

void jump(double height, t_player *player)
{
	t_player temp;

	temp = *player;
	temp.pos_y = temp.pos_y - height;
	get_hit_box(&temp);
	if (check_walls(temp.P_box, data()->map) && act()->jumping * height < 3)
	{
		*player = temp;
		act()->jumping += 1;
	}
	else
	{
		eng()->keys.space = 0;
		act()->jumping = 0;
	}
}

void gravity(t_player *player, double velocity, t_map map)
{
	t_player temp;

	temp = *player;
	temp.pos_y = temp.pos_y + velocity;
	get_hit_box(&temp);
	if (check_gravity(temp.P_box, map))
	{
		if (temp.P_box.right_down_y >= map.max_y - 0.1 || \
			temp.P_box.down_y >= map.max_y - 0.1 || \
			map.map[(int)temp.P_box.down_y][(int)temp.P_box.down_x] == 'L' && \
			map.map[(int)temp.P_box.right_down_y][(int)temp.P_box.right_down_x] == 'L')
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
	if (check_walls(temp.P_box, data()->map))
		objs()->player = temp;
	animate_walk(&act()->walk_action);
	if (x > 0)
		act()->last_action = 0;
	else
		act()->last_action = 1;
}
