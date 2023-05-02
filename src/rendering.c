/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:23:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/02 22:54:45 by sde-mull         ###   ########.fr       */
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
	player->P_box.normal_x = player->pos_x;
	player->P_box.normal_y = player->pos_y;
	player->P_box.right_x = player->pos_x + 1;
	player->P_box.right_y = player->pos_y;
	player->P_box.down_x = player->pos_x;
	player->P_box.down_y = player->pos_y + 1;
	player->P_box.right_down_x = player->pos_x + 1;
	player->P_box.right_down_y = player->pos_y + 1;
}

int render(t_win *win)
{
    get_fps();
    if (data()->map.get_map_flag == 1)
        save_map(data()->map.map_nbr);
	get_hit_box(&objs()->player);
	// if (eng()->keys.space == 1 && !act()->falling)
	// 	jump(0.06);
	// if (!act()->jumping)
	// 	gravity(&objs()->player, 0.06);
	paint_all();
	mlx_put_image_to_window(win->mlx, win->mlx_win, canvas()->game.mlx_img, 0, 0);
    return (0);
}