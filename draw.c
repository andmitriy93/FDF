/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:44:08 by dmian             #+#    #+#             */
/*   Updated: 2020/02/20 18:34:36 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bresenham(t_coord dota, t_coord dotb, t_fdf *data)
{
	float		x_step;
	float		y_step;
	int			maxx;

	dota.z = data->z_matrix[(int)dota.y][(int)dota.x];
	dotb.z = data->z_matrix[(int)dotb.y][(int)dotb.x];
	data->color = (dota.z || dotb.z) ? data->new_color : 0xffffff;
	altitude(&dota, &dotb, data);
	ft_zooming(&dota, &dotb, data);
	ft_shift(&dota, &dotb, data);
	x_step = dotb.x - dota.x;
	y_step = dotb.y - dota.y;
	maxx = max(mod(x_step), mod(y_step));
	x_step /= maxx;
	y_step /= maxx;
	while ((int)(dota.x - dotb.x) || (int)(dota.y - dotb.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			dota.x, dota.y, data->color);
		dota.x += x_step;
		dota.y += y_step;
	}
}

void		draw(t_fdf *data)
{
	t_coord	dota;
	t_coord	dotb;

	dota.y = 0;
	while (dota.y < data->height)
	{
		dota.x = 0;
		while (dota.x < data->width)
		{
			if (dota.x < data->width - 1)
			{
				dotb.x = dota.x + 1;
				dotb.y = dota.y;
				bresenham(dota, dotb, data);
			}
			if (dota.y < data->height - 1)
			{
				dotb.x = dota.x;
				dotb.y = dota.y + 1;
				bresenham(dota, dotb, data);
			}
			dota.x += 1;
		}
		dota.y += 1;
	}
}
