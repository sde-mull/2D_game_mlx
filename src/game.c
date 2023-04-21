/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:42:43 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/21 22:57:16 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void init_values(void)
{
    data()->map.map_nbr = 1;
    data()->map.get_map_flag = 1;
}

int main(int argc, char *argv[])
{
    if (argc > 2)
        return (printf("only one file required\n"));
    init_values();
    window_management();
    return (0);
}