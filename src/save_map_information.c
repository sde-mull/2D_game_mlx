/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map_information.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:16:46 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/26 16:52:02 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void get_max_values(int *fd)
{
   int x;
   int y;
   char *str;

   y = 0;
   x = 0;
   str = get_next_line(*fd);
   while (str[x])
    x++;
   while (str)
    {
        free (str);
        str = get_next_line(*fd);
        y++;   
    }
    free(str);
    data()->map.max_y = y;
    data()->map.max_x = x;
    close(*fd);
}

void save_map(int map_nbr)
{
    int fd;
    int y;

    y = -1;
    if (data()->map.map)
        free_array(data()->map.map);
    fd = open(data()->map_paths[map_nbr], O_RDONLY);
    get_max_values(&fd);
    fd = open(data()->map_paths[map_nbr], O_RDONLY);
    data()->map.map = (char **)malloc(sizeof(char *) * (data()->map.max_y + 1));
    if (!data()->map.map)
        return ;
    while (++y < data()->map.max_y)
        data()->map.map[y] = get_next_line(fd);
    data()->map.map[y] = 0;
    data()->map.get_map_flag = 0;
    close(fd);
    if (canvas()->game.mlx_img)
        mlx_destroy_image(win()->mlx, canvas()->game.mlx_img);
    canvas()->game = new_image(win(), data()->map.max_x * ICON, data()->map.max_y * ICON);
    if (canvas()->resized_background.mlx_img)
        mlx_destroy_image(win()->mlx, canvas()->game.mlx_img);
    canvas()->resized_background = new_image(win(), WIN_WIDTH, WIN_HEIGHT);
    create_background();
    get_background();
}