/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:19:54 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/27 20:52:19 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void init_values(char **argv)
{
    data()->map.map_nbr = 1;
    data()->map.get_map_flag = 1;
    data()->map_paths = argv;
}