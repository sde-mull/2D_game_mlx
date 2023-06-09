/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:10:28 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/13 00:19:15 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void action_movement(void)
{
	if (!act()->last_action)
		    paint_icon(canvas()->player_walk_right[act()->walk_action], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON, &canvas()->game);
    if (act()->last_action)
			paint_icon(canvas()->player_walk_left[act()->walk_action], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON, &canvas()->game);
}

void action_jumping(void)
{
	if (act()->jumping)
	{
		if (act()->last_action)
			paint_icon(canvas()->player_jumping[0], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON, &canvas()->game);
		else
			paint_icon(canvas()->player_jumping[1], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON, &canvas()->game);
	}
}

void action_falling(void)
{
	if (act()->falling)
	{
		if (act()->last_action)
			paint_icon(canvas()->player_falling[0], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON, &canvas()->game);
		else
			paint_icon(canvas()->player_falling[1], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON, &canvas()->game);
	}
}

void action_standard(void)
{
	if (((eng()->keys.arr_left == 0 && eng()->keys.arr_right == 0) || (eng()->keys.arr_left == 1\
		&& eng()->keys.arr_right == 1)) && !act()->jumping && !act()->falling)
	{
			act()->walk_action = 0;
			if (act()->last_action == 0)
    			paint_icon(canvas()->player_normal_right[act()->player], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON, &canvas()->game);
			else if (act()->last_action == 1)
				paint_icon(canvas()->player_normal_left[act()->player], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON, &canvas()->game);
	}
}
