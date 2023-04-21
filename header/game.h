/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:39:16 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/21 22:21:30 by sde-mull         ###   ########.fr       */
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

void init_values(void);

#endif