/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:57:00 by dmian             #+#    #+#             */
/*   Updated: 2020/02/20 18:23:27 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	threedimensional(t_coord *thrd, t_coord *thrd2)
{
	thrd->x = (thrd->x - thrd->y) * cos(0.8);
	thrd->y = (thrd->x + thrd->y) * sin(0.8) - thrd->z;
	thrd2->x = (thrd2->x - thrd2->y) * cos(0.8);
	thrd2->y = (thrd2->x + thrd2->y) * sin(0.8) - thrd2->z;
}

void	ft_zooming(t_coord *dota, t_coord *dotb, t_fdf *data)
{
	dota->x *= data->zoom;
	dota->y *= data->zoom;
	dotb->x *= data->zoom;
	dotb->y *= data->zoom;
	if (data->thrd)
		threedimensional(dota, dotb);
}

void	ft_shift(t_coord *dota, t_coord *dotb, t_fdf *data)
{
	dota->x += 400 + data->shift_x;
	dota->y += 400 + data->shift_y;
	dotb->x += 400 + data->shift_x;
	dotb->y += 400 + data->shift_y;
}

void	altitude(t_coord *dota, t_coord *dotb, t_fdf *data)
{
	dota->z *= data->altitude;
	dotb->z *= data->altitude;
}
