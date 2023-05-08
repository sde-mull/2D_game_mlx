/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:13:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/08 01:52:38 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void animation(void)
{
    animate_lava(&act()->lava);
	animate_door(data()->collected, data()->max_coll, &act()->door);
	animate_coin(&act()->coin);
	check_action(eng()->keys);
    cap_fps(120);
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
	if (*lava == 3)
		*lava = 0;
}

void animate_coin(int *coin)
{
	static int count;

	count++;
	if (count == 20)
	{
		(*coin)++;
		count = 0;
	}
	if (*coin == 7)
		*coin = 0;
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