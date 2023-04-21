/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:23:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/21 23:01:06 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

int get_path(int map_nbr)
{
    return (0);
}

void get_max_values(int fd)
{
   
}

void save_map(int map_nbr)
{
    int fd;

    if (data()->map.map)
        free(data()->map.map);
    //get_max_values(fd);
}

int render(void)
{
    if (data()->map.get_map_flag == 1)
        save_map(data()->map.map_nbr);
    return (0);
}