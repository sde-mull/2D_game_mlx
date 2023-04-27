/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:54:31 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/27 16:33:24 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	double rate_x;
	double rate_y;
	double paint_x;
	double paint_y;
	unsigned int color;
	int x;
	int y;
} t_resize;

typedef struct s_player
{
	int start_x;
	int start_y;
	double pos_x;
	double pos_y;
}	t_player;

#endif