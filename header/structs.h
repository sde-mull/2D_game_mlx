/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:54:31 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/24 20:32:23 by sde-mull         ###   ########.fr       */
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

#endif