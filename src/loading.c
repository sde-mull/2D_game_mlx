/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:31:08 by sde-mull          #+#    #+#             */
/*   Updated: 2023/05/17 19:06:14 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"
# include <pthread.h>

void    free_loading_images(t_win *win)
{
    int i;

    i = 0;
    mlx_destroy_image(win->mlx, canvas()->loading_img.mlx_img);
    mlx_destroy_image(win->mlx, canvas()->loading_screen.mlx_img);
    mlx_destroy_image(win->mlx, canvas()->resized_loading.mlx_img);
    while (i < 60)
    {
        mlx_destroy_image(win->mlx, canvas()->loading_letters[i].mlx_img);
        i++;
    }
    pthread_mutex_destroy(&eng()->load_lock);
}

void    *loading(void* arg)
{
    int i;
    int flg;

    i = 0;
    flg = 0;
    while (!flg)
    {
        usleep(110000);
        pthread_mutex_lock(&eng()->load_lock);
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
        if (data()->loading == 1)
            flg = 1;
        pthread_mutex_unlock(&eng()->load_lock);
        
    }
    return (NULL);
}

int    create_process(void)
{
    if (pthread_create(&eng()->loading, NULL, &loading, NULL))
        return (1);
    init_images(win());
    pthread_mutex_lock(&eng()->load_lock);
    data()->loading = 1;
    pthread_mutex_unlock(&eng()->load_lock);
    if (pthread_join(eng()->loading, NULL) != 0)
			return (2);
    free_loading_images(win());
    return(0);
}