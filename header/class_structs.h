/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:49:48 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/17 18:47:03 by sde-mull         ###   ########.fr       */
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
    int     lava;
    int     cristal;
    int     door;
    int     player;
}   t_action;

typedef struct s_data
{
   t_map map;
   char **map_paths;
   int  max_coll;
   int  collected;
   int  loading;
   int  loading_img;
   int  loading_letters;
   int  resized_img;
} t_data;

typedef struct s_objects
{
    t_player player;
} t_objects;

typedef struct s_canvas
{
    t_img loading_screen;
    t_img loading_img;
    t_img resized_loading;
    t_img loading_letters[60];
    t_img game;
    t_img background[5];
    t_img resized_background;
    t_img tile_surface;
    t_img tile_underground;
    t_img player_walk_right[6];
    t_img player_walk_left[6];
    t_img player_normal_left[2];
    t_img player_normal_right[2];
    t_img player_jumping[2];
    t_img player_falling[2];
    t_img lava[4];
    t_img cristal[24];
    t_img door[13];
}   t_canvas;

typedef struct s_engine
{
    pthread_t       loading;
    pthread_mutex_t load_lock;
    t_keys keys;
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