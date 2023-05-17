/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:21:18 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/17 19:22:12 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

bool	init_window(t_win *win)
{
	win->mlx = mlx_init();
	if (win->mlx == NULL)
		return (WIN_ERROR);
	win->mlx_win = mlx_new_window(win->mlx, WIN_WIDTH, WIN_HEIGHT, "Game");
	if (win->mlx_win == NULL)
	{
        free(win->mlx);
		return (WIN_ERROR);
	}
	return (WIN_SUCCESS);
}

void window_management(void)
{
	XInitThreads();
    init_window(win());
	// init_images(win());
	create_process();
    mlx_hook(win()->mlx_win , 17, 0, exit_game, NULL);
	mlx_hook(win()->mlx_win, 2, 1L << 0, scan_key, NULL);
	mlx_hook(win()->mlx_win, 3, 1L << 1, scan_key_release, win());
	mlx_loop_hook(win()->mlx, render, win());
    mlx_loop(win()->mlx);
}
