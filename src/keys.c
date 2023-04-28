/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:29:39 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/28 10:37:19 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

int scan_key_release(int keycode)
{
    if (keycode == ARROW_LEFT)
        eng()->keys.arr_left = 0;
    if (keycode == ARROW_RIGHT)
        eng()->keys.arr_right = 0;
    return (0);
}

int scan_key(int keycode)
{
    if (keycode == ESC)
        exit_game();
    if (keycode == ARROW_LEFT)
        eng()->keys.arr_left = 1;
    if (keycode == ARROW_RIGHT)
        eng()->keys.arr_right = 1;
    if (!act()->falling && keycode == SPACE)
        eng()->keys.space = 1;
    return (0);
}