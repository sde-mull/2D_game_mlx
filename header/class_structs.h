/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:49:48 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/26 16:52:41 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_STRUCTS_H
# define CLASS_STRUCTS_H

typedef struct s_data
{
   t_map map;
   char **map_paths;
} t_data;

typedef struct s_objects
{
    
} t_objects;

typedef struct s_canvas
{
    t_img game;
    t_img background[5];
}   t_canvas;

typedef struct s_engine
{
    
}   t_engine;

typedef struct s_win
{
    void			*mlx;
	void			*mlx_win;
	int				w;
	int				h;   
}   t_win;

//functions

t_win       *win(void);
t_canvas    *canvas(void);
t_data      *data(void);
t_objects   *objs(void);
t_engine    *eng(void);

#endif