/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:06:27 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/08 01:09:11 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"


void check_collected(int x, int y, char **map)
{
	if (map[y][x] == 'C')
	{
		map[y][x] = '0';
		data()->collected += 1;
	}
}

void check_enter(t_data *data, t_player player)
{
	if (data->map.map[(int)player.pos_y - 1][(int)player.pos_x] == 'E' && \
		data->max_coll == data->collected)
			exit_game();
}

void check_movement(t_player *player)
{
	if (eng()->keys.arr_left == 1)
		move(-1, 0, player);
	if (eng()->keys.arr_right == 1)
		move(1, 0, player);
	if (eng()->keys.arr_up == 1)
		check_enter(data(), *player);
}

void check_action(t_keys keys)
{
	action_standard();
	action_falling();
	action_jumping();
	if (!act()->jumping && !act()->falling && (keys.arr_left != 0 || keys.arr_right != 0) && \
		(keys.arr_left != 1 || keys.arr_right != 1))
		action_movement();
}

int check_walls(t_box box, t_map map)
{
	if (map.map[(int)box.normal_y][(int)(box.normal_x - X_MARGIN)] != '2' && \
		map.map[(int)(box.down_y)][(int)(box.down_x - X_MARGIN)] != '2'&& \
		map.map[(int)(box.right_down_y)][(int)(box.right_down_x + X_MARGIN)] != '2' && \
		map.map[(int)(box.right_y)][(int)(box.right_x + X_MARGIN)] != '2' &&\
		box.normal_x > 0  && box.right_x < map.max_x && box.normal_y > 0 && box.right_y > 0)
			return (1);
	return (0);
}

void collectible(t_map map, t_box box)
{
	if (act()->last_action)
	{
		check_collected(box.normal_x, box.normal_y, map.map);
		check_collected(box.down_x, box.down_y, map.map);
	}
	if (!act()->last_action)
	{
		check_collected(box.right_x, box.right_y, map.map);
		check_collected(box.right_down_x, box.right_down_y, map.map);
	}
}
