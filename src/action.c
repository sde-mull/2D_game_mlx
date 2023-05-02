/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:10:28 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/02 23:13:33 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void check_action(void)
{
	if (((eng()->keys.arr_left == 0 && eng()->keys.arr_right == 0) || (eng()->keys.arr_left == 1\
		&& eng()->keys.arr_right == 1)) && !act()->jumping && !act()->falling)
	{
			act()->walk_action = 0;
			if (act()->last_action == 0)
    			paint_icon(canvas()->player_normal_right, objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
			else if (act()->last_action == 1)
				paint_icon(canvas()->player_normal_left, objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
	}
	if (act()->falling)
	{
		if (act()->last_action)
			paint_icon(canvas()->player_falling[0], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
		else
			paint_icon(canvas()->player_falling[1], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
	}
	if (act()->jumping)
	{
		if (act()->last_action)
			paint_icon(canvas()->player_jumping[0], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
		else
			paint_icon(canvas()->player_jumping[1], objs()->player.pos_x * ICON, objs()->player.pos_y * ICON);
	}
}