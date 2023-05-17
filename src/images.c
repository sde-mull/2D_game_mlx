/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:27:09 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/17 19:00:31 by sde-mull         ###   ########.fr       */
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
	char 	*str1;
	char 	*str2;
	char 	*place;
	char	*path;
	char	*temp;
	int 	i;

	str1 = ft_strdup("images/xpm/collectible/cristal");
	str2 = ft_strdup(".xpm");
	i = 0;
	while (i < 24)
	{
		place = ft_itoa(i + 1);
		temp = ft_strjoin(place, str2);
		path = ft_strjoin(str1, temp);
		canvas()->cristal[i] = load_images(win, path);
		free(path);
		free(place);
		free(temp);
		i++;
	}
	free(str1);
	free(str2);
}

void	init_door(t_win *win)
{
	canvas()->door[0] = load_images(win, "images/xpm/door/door1.xpm");
	canvas()->door[1] = load_images(win, "images/xpm/door/door2.xpm");
	canvas()->door[2] = load_images(win, "images/xpm/door/door3.xpm");
	canvas()->door[3] = load_images(win, "images/xpm/door/door4.xpm");
	canvas()->door[4] = load_images(win, "images/xpm/door/door5.xpm");
	canvas()->door[5] = load_images(win, "images/xpm/door/door6.xpm");
	canvas()->door[6] = load_images(win, "images/xpm/door/door7.xpm");
	canvas()->door[7] = load_images(win, "images/xpm/door/door8.xpm");
	canvas()->door[8] = load_images(win, "images/xpm/door/door9.xpm");
	canvas()->door[9] = load_images(win, "images/xpm/door/door10.xpm");
	canvas()->door[10] = load_images(win, "images/xpm/door/door11.xpm");
	canvas()->door[11] = load_images(win, "images/xpm/door/door12.xpm");
	canvas()->door[12] = load_images(win, "images/xpm/door/door13.xpm");
}

void	init_player(t_win *win)
{
	sprite_left(win);
	sprite_right(win);
}

void	init_loading_letters(t_win *win)
{
	char 	*str1;
	char 	*str2;
	char 	*place;
	char	*path;
	char	*temp;
	int 	i;

	str1 = ft_strdup("images/xpm/loading/letters/letters");
	str2 = ft_strdup(".xpm");
	i = 0;
	while (i < 60)
	{
		place = ft_itoa(i + 1);
		temp = ft_strjoin(place, str2);
		path = ft_strjoin(str1, temp);
		canvas()->loading_letters[i] = load_images(win, path);
		free(path);
		free(place);
		free(temp);
		i++;
	}
	free(str1);
	free(str2);
}

void	init_loading(t_win *win)
{
	canvas()->loading_screen = new_image(win, WIN_WIDTH, WIN_HEIGHT);
    canvas()->resized_loading = new_image(win, WIN_WIDTH, WIN_HEIGHT);
	canvas()->loading_img = load_images(win, "images/xpm/loading/background.xpm");
    create_background(canvas()->loading_img, &canvas()->resized_loading);
	pthread_mutex_lock(&eng()->load_lock);
	data()->loading_img = 1;
	pthread_mutex_unlock(&eng()->load_lock);
	init_loading_letters(win);
	pthread_mutex_lock(&eng()->load_lock);
	data()->loading_letters = 1;
	pthread_mutex_unlock(&eng()->load_lock);
}

void	init_images(t_win *win)
{
	init_loading(win);
	init_background(win);
	init_cristal(win);
	init_lava(win);
	init_player(win);
	init_door(win);
}
