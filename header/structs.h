/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:54:31 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/04 19:40:57 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_box
{
	double normal_x;
	double normal_y;
	double right_x;
	double right_y;
	double down_x;
	double down_y;
	double right_down_x;
	double right_down_y;
}	t_box;

typedef struct s_map
{
    int     get_map_flag;
    int     map_nbr;
    char    **map;
    int     max_x;
    int     max_y;
}   t_map;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				imgx;
	int				imgy;
}					t_img;

typedef struct s_resize
{
	double 			rate_x;
	double			rate_y;
	double 			paint_x;
	double 			paint_y;
	unsigned int 	color;
	int 			x;
	int 			y;
} t_resize;

typedef struct s_player
{
	int 	start_x;
	int 	start_y;
	double	pos_x;
	double 	pos_y;
	t_box	P_box;
}	t_player;

typedef struct s_keys
{
	int arr_left;
	int arr_right;
	int space;
}	t_keys;


#endif