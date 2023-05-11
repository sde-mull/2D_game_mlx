/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:13:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/11 01:20:01 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void animation(void)
{
    animate_lava(&act()->lava);
	animate_door(data()->collected, data()->max_coll, &act()->door);
	animate_cristal(&act()->coin);
	animate_player(&act()->player);
	check_action(eng()->keys);
    cap_fps(100);
}

void animate_lava(int *lava)
{
	static int count;

	count++;
	if (count == 50)
	{
		(*lava)++;
		count = 0;
	}
	if (*lava == 4)
		*lava = 0;
}

void animate_cristal(int *cristal)
{
	static int count;

	count++;
	if (count == 20)
	{
		(*cristal)++;
		count = 0;
	}
	if (*cristal == 24)
		*cristal = 0;
}

void animate_door(int coll, int max, int *door)
{
	static int count;

	if (max == coll)
		count++;
	if (count == 60 && *door != 5)
	{
		(*door)++;
		count = 0;
	}
}

void animate_walk(int *walk)
{
	static int count;

	count++;
	if (count == 10)
	{
		(*walk)++;
		count = 0;
	}
	if (*walk == 6)
		*walk = 0;
}

void animate_player(int *player)
{
	static int count;

	count++;
	if (count == 50)
	{
		(*player)++;
		count = 0;
	}
	if (*player == 2)
		*player = 0;
}