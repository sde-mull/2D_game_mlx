/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:49:48 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/06 02:39:50 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_STRUCTS_H
# define CLASS_STRUCTS_H

typedef struct s_action
{
    int 	walk_action;
    int     last_action;
    int     falling;
    int     jumping;
    int     walk_left;
    int     walk_right;
    int     lava;
    int     hit_wall;
    int     mid_air;
}   t_action;

typedef struct s_data
{
   t_map map;
   char **map_paths;
} t_data;

typedef struct s_objects
{
    t_player player;
} t_objects;

typedef struct s_canvas
{
    t_img game;
    t_img background[5];
    t_img resized_background;
    t_img tile_surface;
    t_img tile_underground;
    t_img player_walk_right[6];
    t_img player_walk_left[6];
    t_img player_normal_left;
    t_img player_normal_right;
    t_img player_jumping[2];
    t_img player_falling[2];
    t_img lava[4];
}   t_canvas;

typedef struct s_engine
{
    t_keys keys;
    int abs_pos_y;
    int abs_pos_x;
}   t_engine;

typedef struct s_win
{
    void			*mlx;
	void			*mlx_win;
	int				w;
	int				h;
    int             redirection; 
}   t_win;

//functions

t_win       *win(void);
t_canvas    *canvas(void);
t_data      *data(void);
t_objects   *objs(void);
t_engine    *eng(void);
t_action    *act(void);

#endif