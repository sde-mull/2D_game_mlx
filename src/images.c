/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:27:09 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/11 22:48:36 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

t_img	new_image(t_win *win, int x, int y)
{
	t_img	img;

	img.mlx_img = mlx_new_image(win->mlx, x, y);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

t_img	load_images(t_win *win, char *str)
{
	t_img img;

	img.mlx_img = mlx_xpm_file_to_image(win->mlx, str, &img.imgx, &img.imgy);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

void	init_background(t_win *win)
{
	canvas()->tile_surface = load_images(win, "images/xpm/tiles/Tile_surface.xpm");
	canvas()->tile_underground = load_images(win, "images/xpm/tiles/Tile_underground.xpm");
	canvas()->background[0] = load_images(win, "images/xpm/background/background.xpm");
}

void	sprite_left(t_win *win)
{
	canvas()->player_normal_left[0]  = load_images(win, "images/xpm/player/sasuke/left/normal_left.xpm");
	canvas()->player_normal_left[1]  = load_images(win, "images/xpm/player/sasuke/left/normal_left2.xpm");
	canvas()->player_walk_left[0] = load_images(win, "images/xpm/player/sasuke/left/walk/walk1.xpm");
	canvas()->player_walk_left[1] = load_images(win, "images/xpm/player/sasuke/left/walk/walk2.xpm");
	canvas()->player_walk_left[2] = load_images(win, "images/xpm/player/sasuke/left/walk/walk3.xpm");
	canvas()->player_walk_left[3] = load_images(win, "images/xpm/player/sasuke/left/walk/walk4.xpm");
	canvas()->player_walk_left[4] = load_images(win, "images/xpm/player/sasuke/left/walk/walk5.xpm");
	canvas()->player_walk_left[5] = load_images(win, "images/xpm/player/sasuke/left/walk/walk6.xpm");
	canvas()->player_jumping[0] = load_images(win, "images/xpm/player/sasuke/left/jump_left.xpm");
	canvas()->player_falling[0] = load_images(win, "images/xpm/player/sasuke/left/falling_left.xpm");
}

void	sprite_right(t_win *win)
{
	canvas()->player_walk_right[0] = load_images(win, "images/xpm/player/sasuke/right/walk/walk1.xpm");
	canvas()->player_walk_right[1] = load_images(win, "images/xpm/player/sasuke/right/walk/walk2.xpm");
	canvas()->player_walk_right[2] = load_images(win, "images/xpm/player/sasuke/right/walk/walk3.xpm");
	canvas()->player_walk_right[3] = load_images(win, "images/xpm/player/sasuke/right/walk/walk4.xpm");
	canvas()->player_walk_right[4] = load_images(win, "images/xpm/player/sasuke/right/walk/walk5.xpm");
	canvas()->player_walk_right[5] = load_images(win, "images/xpm/player/sasuke/right/walk/walk6.xpm");
	canvas()->player_falling[1] = load_images(win, "images/xpm/player/sasuke/right/falling_right.xpm");
	canvas()->player_jumping[1] = load_images(win, "images/xpm/player/sasuke/right/jump_right.xpm");
	canvas()->player_normal_right[0] = load_images(win, "images/xpm/player/sasuke/right/normal_right.xpm");
	canvas()->player_normal_right[1] = load_images(win, "images/xpm/player/sasuke/right/normal_right2.xpm");
}

void	init_lava(t_win *win)
{
	canvas()->lava[0] = load_images(win, "images/xpm/lava/lava1.xpm");
	canvas()->lava[1] = load_images(win, "images/xpm/lava/lava2.xpm");
	canvas()->lava[2] = load_images(win, "images/xpm/lava/lava3.xpm");
	canvas()->lava[3] = load_images(win, "images/xpm/lava/lava4.xpm");
}

void	init_cristal(t_win *win)
{
	canvas()->cristal[0] = load_images(win, "images/xpm/collectible/cristal.xpm");
	canvas()->cristal[1] = load_images(win, "images/xpm/collectible/cristal2.xpm");
	canvas()->cristal[2] = load_images(win, "images/xpm/collectible/cristal3.xpm");
	canvas()->cristal[3] = load_images(win, "images/xpm/collectible/cristal4.xpm");
	canvas()->cristal[4] = load_images(win, "images/xpm/collectible/cristal5.xpm");
	canvas()->cristal[5] = load_images(win, "images/xpm/collectible/cristal6.xpm");
	canvas()->cristal[6] = load_images(win, "images/xpm/collectible/cristal7.xpm");
	canvas()->cristal[7] = load_images(win, "images/xpm/collectible/cristal8.xpm");
	canvas()->cristal[8] = load_images(win, "images/xpm/collectible/cristal9.xpm");
	canvas()->cristal[9] = load_images(win, "images/xpm/collectible/cristal10.xpm");
	canvas()->cristal[10] = load_images(win, "images/xpm/collectible/cristal11.xpm");
	canvas()->cristal[11] = load_images(win, "images/xpm/collectible/cristal12.xpm");
	canvas()->cristal[12] = load_images(win, "images/xpm/collectible/cristal13.xpm");
	canvas()->cristal[13] = load_images(win, "images/xpm/collectible/cristal14.xpm");
	canvas()->cristal[14] = load_images(win, "images/xpm/collectible/cristal15.xpm");
	canvas()->cristal[15] = load_images(win, "images/xpm/collectible/cristal16.xpm");
	canvas()->cristal[16] = load_images(win, "images/xpm/collectible/cristal17.xpm");
	canvas()->cristal[17] = load_images(win, "images/xpm/collectible/cristal18.xpm");
	canvas()->cristal[18] = load_images(win, "images/xpm/collectible/cristal19.xpm");
	canvas()->cristal[19] = load_images(win, "images/xpm/collectible/cristal20.xpm");
	canvas()->cristal[20] = load_images(win, "images/xpm/collectible/cristal21.xpm");
	canvas()->cristal[21] = load_images(win, "images/xpm/collectible/cristal22.xpm");
	canvas()->cristal[22] = load_images(win, "images/xpm/collectible/cristal23.xpm");
	canvas()->cristal[23] = load_images(win, "images/xpm/collectible/cristal24.xpm");
}

void	init_door(t_win *win)
{
	canvas()->door[0] = load_images(win, "images/xpm/door/door1.xpm");
	canvas()->door[1] = load_images(win, "images/xpm/door/door2.xpm");
	canvas()->door[2] = load_images(win, "images/xpm/door/door3.xpm");
	canvas()->door[3] = load_images(win, "images/xpm/door/door4.xpm");
	canvas()->door[4] = load_images(win, "images/xpm/door/door5.xpm");
	canvas()->door[5] = load_images(win, "images/xpm/door/door6.xpm");
}

void	init_player(t_win *win)
{
	sprite_left(win);
	sprite_right(win);
}
void	init_images(t_win *win)
{
	init_background(win);
	init_cristal(win);
	init_lava(win);
	init_player(win);
	init_door(win);
}