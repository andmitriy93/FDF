/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:52:35 by dmian             #+#    #+#             */
/*   Updated: 2020/02/20 15:52:03 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		deal_key(int key, fdf *data)
{
	if (key == 126)
		data->shift_y -= 20;
	if (key == 125)
		data->shift_y += 20;
	if (key == 123)
		data->shift_x -= 20;
	if (key == 124)
		data->shift_x += 20;
	if (key == 69)
		data->zoom += 20;
	if (key == 78)
	{
		if (data->zoom > 0)
		{
			data->zoom -= 20;
		}
	}
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		main(int ac, char **av)
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	data->shift_x = 0;
	data->shift_y = 0;
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;

	//bresenham(10, 10, 600, 300, data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	while (1)
	;
}
