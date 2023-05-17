/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:23:53 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/17 19:46:41 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

int render(t_win *win)
{

    if (data()->map.get_map_flag == 1)
        save_map(data()->map.map_nbr);
	game(win);
    return (0);
}