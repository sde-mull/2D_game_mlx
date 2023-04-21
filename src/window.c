/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:21:18 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/21 20:47:01 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

int	exit_game(void)
{
	if (win()->mlx_win)
	{
		mlx_destroy_window(win()->mlx, win()->mlx_win);
		win()->mlx_win = NULL;
		mlx_loop_end(win()->mlx);
	}
	return (0);
}


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
    init_window(win());
    mlx_hook(win()->mlx_win , 17, 0, exit_game, NULL);
	mlx_hook(win()->mlx_win, 2, 1L << 0, scan_key, &win);
	// mlx_hook(win()->mlx_win, 3, 1L << 1, scan_key_release, &win);
	mlx_loop_hook(win()->mlx, &render, NULL);
    mlx_loop(win()->mlx);
}
