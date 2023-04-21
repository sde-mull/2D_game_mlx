/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:54:31 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/21 22:46:18 by sde-mull         ###   ########.fr       */
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
    char    *prefix;
    char    *sufix;
}   t_map;

#endif