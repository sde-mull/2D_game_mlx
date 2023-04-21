/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-mull <sde-mull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:35:17 by sde-mull          #+#    #+#             */
/*   Updated: 2023/04/21 19:14:51 by sde-mull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/game.h"

t_win *win(void)
{
	static t_win win;

	return (&win);
}

t_canvas *canvas(void)
{
	static t_canvas canv;

	return (&canv);
}

t_data *data(void)
{
	static t_data data;

	return (&data);
}

t_objects *objs(void)
{
	static t_objects objs;

	return (&objs);
}

t_engine *eng(void)
{
	static t_engine eng;

	return (&eng);
}