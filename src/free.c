/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:13:11 by kuhaku            #+#    #+#             */
/*   Updated: 2023/04/25 22:16:39 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free (arr[i++]);
	free (arr);
}

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

void free_win(t_win *win)
{
	mlx_destroy_image(win->mlx, canvas()->game.mlx_img);
	if (win->mlx_win)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		win->mlx_win = NULL;
	}
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	if (data()->map.map)
		free_array(data()->map.map);
}