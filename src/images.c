/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:27:09 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/05 23:55:54 by sde-mull         ###   ########.fr       */
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
	canvas()->background[0] = load_images(win, "images/xpm/background/final_battle1.xpm");
	//canvas()->background[1] = load_images(win, "images/xpm/background/ice_battle1.xpm");
	// canvas()->background[2] = load_images(win, "images/xpm/background/mid_battle1.xpm");
	// canvas()->background[3] = load_images(win, "images/xpm/background/night_battle1.xpm");
	// canvas()->background[4] = load_images(win, "images/xpm/background/start_battle1.xpm");
}

void	sprite_left(t_win *win)
{
	canvas()->player_normal_left  = load_images(win, "images/xpm/player/sasuke/left/normal_left.xpm");
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
	canvas()->player_normal_right = load_images(win, "images/xpm/player/sasuke/right/normal_right.xpm");
}

void	init_lava(t_win *win)
{
	canvas()->lava[0] = load_images(win, "images/xpm/lava/lava1.xpm");
	canvas()->lava[1] = load_images(win, "images/xpm/lava/lava2.xpm");
	canvas()->lava[2] = load_images(win, "images/xpm/lava/lava3.xpm");
	canvas()->lava[3] = load_images(win, "images/xpm/lava/lava4.xpm");
}

void	init_player(t_win *win)
{
	sprite_left(win);
	sprite_right(win);
}
void	init_images(t_win *win)
{
	init_background(win);
	init_lava(win);
	init_player(win);
}