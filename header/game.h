/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:39:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/08 22:50:25 by sde-mull         ###   ########.fr       */
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

//action.c
void 			action_movement(void);
void 			action_jumping(void);
void 			action_falling(void);
void 			action_standard(void);

//animation.c
void 			animation(void);
void 			animate_lava(int *lava);
void 			animate_door(int coll, int max, int *door);
void 			animate_coin(int *coin);
void            animate_player(int *player);
void            animate_walk(int *walk);

//background.c
void 			get_background(void);
void 			create_background(void);

//check.c
void 			check_collected(int x, int y, char **map);
void 			collectible(t_map map, t_box box);
void 			check_enter(t_data *data, t_player player);
void 			check_movement(t_player *player);
void 			check_action(t_keys keys);
int  			check_walls(t_box box, t_map map);
int             check_gravity(t_box box, t_map map);

//engine.c
void 			engine(void);
void 			jump(double height, t_player *player);
void 			gravity(t_player *player, double velocity, t_map map);
void 			move(int x, int y, t_player *player);

//engine2.c
void    		get_fps();
void    		get_hit_box(t_player *player);
void    		recenter_camera(t_player player);
void    		cap_fps(int cap);

//free.c
void    		free_array(char **arr);
int	    		exit_game(void);
void    		free_win(t_win *win);
void    		destroy_images(t_win *win);

//game.c
void 			game(t_win *win);

//images.c
t_img			load_images(t_win *win, char *str);
t_img			new_image(t_win *win, int x, int y);
void			init_background(t_win *win);
void			init_lava(t_win *win);
void			init_coin(t_win *win);
void			init_door(t_win *win);
void			init_player(t_win *win);
void			init_images(t_win *win);
void			sprite_left(t_win *win);
void			sprite_right(t_win *win);

//init_values.c
void 			init_values(char **argv);

//key.c
int 			scan_key(int keycode);
int 			scan_key_release(int keycode);

//my_mlx_func.c
void	        my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_get_pixel(t_img *data, int x, int y);

//paint.c
void 			paint_hit_box(t_box box);
void 			paint_icon(t_img img, int pos_x, int pos_y);
void 			paint_objects(t_map map, t_canvas canvas, t_action act);
void 			paint();

//rendering.c
int     		render(t_win *win);

//save_map_information.c
void 			get_max_values(int *fd);
void 			save_map(int map_nbr);
void 			get_player(t_map map, t_player *player);

//tile.c
void 			get_tiles(t_map map);

//Window.c
bool			init_window(t_win *win);
void    		window_management(void);

#endif