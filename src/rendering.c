/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:23:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/06 03:10:23 by sde-mull         ###   ########.fr       */
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

void recenter_camera(void)
{
	if (((int)objs()->player.pos_x + 24) < data()->map.max_x)
	{
		if (((objs()->player.pos_x - 16)) > 0)
			win()->redirection = (objs()->player.pos_x - 16) * 32;
		else
			win()->redirection = 0;
	}
}

int render(t_win *win)
{
    get_fps();
    if (data()->map.get_map_flag == 1)
        save_map(data()->map.map_nbr);
	if (eng()->keys.space == 1 && !act()->falling)
		jump(0.06, &objs()->player);
	if (!act()->jumping)
		gravity(&objs()->player, 0.06);
	paint_all();
	recenter_camera();
	mlx_put_image_to_window(win->mlx, win->mlx_win, canvas()->game.mlx_img, -win->redirection, 0);
    return (0);
}