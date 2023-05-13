/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:31:08 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/13 02:46:45 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

void    *loading(void* arg)
{
    int i;

    i = 0;
    while (!data()->loading)
    {
        usleep(100000);
        if (data()->loading_img)
        {
            get_background(&canvas()->resized_loading, &canvas()->loading_screen, 0);
        }
        if (data()->loading_letters)
        {
            paint_icon(canvas()->loading_letters[i], 0, 0, &canvas()->loading_screen);
            i++;
            if (i == 60)
                i = 0;
        }
        if (data()->loading_img || data()->loading_letters)
            mlx_put_image_to_window(win()->mlx, win()->mlx_win, canvas()->loading_screen.mlx_img, 0, 0);
    }
    return (NULL);
}

int    create_process(void)
{
    if (pthread_create(&eng()->loading, NULL, &loading, NULL))
        return (1);
    init_images(win());
    data()->loading = 1;
    if (pthread_join(eng()->loading, NULL) != 0)
			return (2);
    return(0);
}