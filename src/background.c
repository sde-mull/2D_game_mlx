/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:29:24 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/07 22:00:36 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"


void get_background(void)
{
	char	*src;
	char	*dst;
	int		y;

	y = 0;
	while(y < WIN_HEIGHT) 
	{
    	src = (char*)canvas()->resized_background.addr + y * canvas()->resized_background.line_len;
   		dst = (char*)canvas()->game.addr + y * canvas()->game.line_len + win()->redirection * canvas()->game.bpp / 8;
   		memcpy(dst, src, WIN_WIDTH * canvas()->resized_background.bpp / 8);
		y++;
	}
}

void create_background(void)
{
	t_resize resize;
	t_img img;

	img = canvas()->background[data()->map.map_nbr - 1];
	resize.rate_x = (double)img.imgx /  WIN_WIDTH ;
	resize.rate_y = (double)img.imgy / WIN_HEIGHT;
	resize.paint_y = 0;
	resize.y = 0;
	resize.color = 0;
	while (resize.y < WIN_HEIGHT)
	{
		resize.x = 0;
		resize.paint_x = 0;
		while (resize.x < WIN_WIDTH)
		{
			resize.color = my_mlx_get_pixel(&img, resize.paint_x, resize.paint_y);
			my_mlx_pixel_put(&canvas()->resized_background, resize.x, resize.y, (int)resize.color);
			resize.x++;
			resize.paint_x += resize.rate_x;
		}
		resize.y++;
		resize.paint_y += resize.rate_y;
	}
}