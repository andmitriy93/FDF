/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:44:08 by dmian             #+#    #+#             */
/*   Updated: 2020/02/20 15:53:56 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	threeDimensional(coord	*thrD, coord *thrD2)
{
	thrD->x = (thrD->x - thrD->y) * cos(0.8);
	thrD->y = (thrD->x + thrD->y) * sin(0.8) - thrD->z;

	thrD2->x = (thrD2->x - thrD2->y) * cos(0.8);
	thrD2->y = (thrD2->x + thrD2->y) * sin(0.8) - thrD2->z;
}

void	zoom(coord	*dotA, coord *dotB, fdf *data)
{
	dotA->x *= data->zoom;
	dotA->y *= data->zoom;
	dotB->x *= data->zoom;
	dotB->y *= data->zoom;
}

void	bresenham(coord dotA, coord dotB, fdf *data)
{
	float 	x_step;
	float 	y_step;
	int		maxx;

	dotA.z = data->z_matrix[(int)dotA.y][(int)dotA.x];
	dotB.z = data->z_matrix[(int)dotB.y][(int)dotB.x];

	zoom(&dotA, &dotB, data);
	// color
	data->color = (dotA.z || dotB.z) ? 0x2edd17 : 0xffffff;
	threeDimensional(&dotA, &dotB);
	
	//------shift-------------
	dotA.x +=  400 + data->shift_x;
	dotA.y +=  400 + data->shift_y;
	dotB.x += 400 +	data->shift_x;
	dotB.y += 400 + data->shift_y;

	x_step = dotB.x - dotA.x;
	y_step = dotB.y - dotA.y;
	maxx = max(mod(x_step), mod(y_step));
	x_step /= maxx;
	y_step /= maxx;
	while ((int)(dotA.x - dotB.x) || (int)(dotA.y - dotB.y))
	{
		mlx_pixel_put(data->mlx_ptr,  data->win_ptr,\
		dotA.x, dotA.y, data->color);
		dotA.x += x_step;
		dotA.y += y_step;
	}
}

void	draw(fdf *data)
{
	coord	dotA;
	coord	dotB;
	dotA.y = 0;
	while (dotA.y < data->height)
	{
		dotA.x = 0;
		while (dotA.x < data->width)
		{
			if (dotA.x < data->width - 1)
			{
				dotB.x = dotA.x + 1;
				dotB.y = dotA.y;
				bresenham(dotA, dotB, data);
			}
			if (dotA.y < data->height - 1)
			{
				dotB.x = dotA.x;
				dotB.y = dotA.y + 1;
				bresenham(dotA, dotB, data);
			}
			dotA.x += 1;
		}
		dotA.y += 1;
	}
}
