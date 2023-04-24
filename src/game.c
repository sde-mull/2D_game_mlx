/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:42:43 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/24 20:20:44 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
        return (printf("At least one file required\n"));
    init_values(argv);
    window_management();
    return (0);
}