/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:14:23 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/08 01:26:03 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void game(t_win *win)
{
    engine();
	paint();
	animation();
	mlx_put_image_to_window(win->mlx, win->mlx_win, canvas()->game.mlx_img, -win->redirection, 0);
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        return (printf("At least one file required\n"));
    init_values(argv);
    window_management();
    return (0);
}