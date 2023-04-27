/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:27:09 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/26 16:56:54 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

t_img	new_image(t_win *win, int x, int y)
{
	t_img	img;

	img.mlx_img = mlx_new_image(win->mlx, x, y);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

t_img	load_images(t_win *win, char *str)
{
	t_img img;

	img.mlx_img = mlx_xpm_file_to_image(win->mlx, str, &img.imgx, &img.imgy);
	img.addr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len,\
	&img.endian);
	return (img);
}

void	init_images(t_win *win)
{
	canvas()->background[0] = load_images(win, "images/xpm/background/final_battle1.xpm");
	// canvas()->background[1] = load_images(win, "images/xpm/background/ice_battle1.xpm");
	// canvas()->background[2] = load_images(win, "images/xpm/background/mid_battle1.xpm");
	// canvas()->background[3] = load_images(win, "images/xpm/background/night_battle1.xpm");
	// canvas()->background[4] = load_images(win, "images/xpm/background/start_battle1.xpm");
}