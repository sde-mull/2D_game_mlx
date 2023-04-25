/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:23:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/25 22:14:37 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void get_fps()
{
	struct timeval time;
	static int frames;
	static int second;

	gettimeofday(&time, NULL);
	if (second != time.tv_sec)
	{
		second = time.tv_sec;
		printf("FPS: %d\n", frames);
		frames = 0;
	}
	else
		frames++;
}

int render(void)
{
    get_fps();
    if (data()->map.get_map_flag == 1)
        save_map(data()->map.map_nbr);
    
    return (0);
}