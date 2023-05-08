/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:10:59 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/08 01:19:41 by sde-mull         ###   ########.fr       */
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

void get_hit_box(t_player *player)
{
	player->P_box.normal_x = player->pos_x + 0.1;
	player->P_box.normal_y = player->pos_y + 0.05;
	player->P_box.right_x = player->pos_x + 0.90;
	player->P_box.right_y = player->pos_y + 0.05;
	player->P_box.down_x = player->pos_x + 0.1;
	player->P_box.down_y = player->pos_y + 0.95;
	player->P_box.right_down_x = player->pos_x + 0.90;
	player->P_box.right_down_y = player->pos_y + 0.95;
}

void recenter_camera(t_player player)
{
	if (((int)player.pos_x + 24) < data()->map.max_x)
	{
		if (((player.pos_x - 16)) > 0)
			win()->redirection = (player.pos_x - 16) * ICON;
		else
			win()->redirection = 0;
	}
}

void cap_fps(int cap)
{
	struct timeval time;
	
	const int FPS_CAP = cap;
    const int US_PER_FRAME = 1000000 / FPS_CAP;
    static struct timeval last_frame_time = {0};
    gettimeofday(&time, NULL);
    long elapsed_time = (time.tv_sec - last_frame_time.tv_sec) * 1000000 +
                         time.tv_usec - last_frame_time.tv_usec;
    if (elapsed_time < US_PER_FRAME) {
        usleep(US_PER_FRAME - elapsed_time);
    }
    last_frame_time = time;
}
