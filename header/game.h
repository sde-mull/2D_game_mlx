/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:39:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/04 20:06:02 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
#include <sys/time.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "settings.h"
# include "structs.h"
# include "class_structs.h"
# include "macros.h"

//Window.c
bool	init_window(t_win *win);
void    window_management(void);

//rendering.c
int     render(t_win *win);
void    get_fps();

//key.c
int scan_key(int keycode);
int scan_key_release(int keycode);

//save_map_information.c
void get_max_values(int *fd);
void save_map(int map_nbr);

//init_values.c
void init_values(char **argv);

//images.c
t_img	load_images(t_win *win, char *str);
t_img	new_image(t_win *win, int x, int y);
void	init_images(t_win *win);
void	sprite_left(t_win *win);
void	sprite_right(t_win *win);

//free.c
void	free_array(char **arr);
void    free_win(t_win *win);
int	    exit_game(void);
void    destroy_images(t_win *win);

//my_mlx_func.c

void	        my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_get_pixel(t_img *data, int x, int y);

void create_background(void);
void get_background(void);

void paint_all();
void paint_icon(t_img img, int pos_x, int pos_y);

void get_tiles(void);

void move(int x, int y);
void check_movement(void);
void gravity(t_player *player, double velocity);
void jump(double height);

void check_action(void);
void action_movement(void);
void action_jumping(void);
void action_falling(void);
void action_standard(void);

void get_hit_box(t_player *player);

#endif