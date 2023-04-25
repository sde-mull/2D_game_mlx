/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:39:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/25 22:14:51 by sde-mull         ###   ########.fr       */
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
int	    exit_game(void);
bool	init_window(t_win *win);
void    window_management(void);

//rendering.c
int render(void);

//key.c
int scan_key(int keycode);

//save_map_information.c
void get_max_values(int fd);
void save_map(int map_nbr);

//init_values.c
void init_values(char **argv);

//images.c
t_img	load_images(t_win *win, char *str);
t_img	new_image(t_win *win, int x, int y);
void	init_images(t_win *win);

void	free_array(char **arr);

#endif