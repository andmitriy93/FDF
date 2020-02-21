/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:52:35 by dmian             #+#    #+#             */
/*   Updated: 2020/02/20 18:07:23 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_fdf *data)
{
	data->shift_y -= (key == 126) ? 20 : 0;
	data->shift_y += (key == 125) ? 20 : 0;
	data->shift_x -= (key == 123) ? 20 : 0;
	data->shift_x += (key == 124) ? 20 : 0;
	data->altitude -= (key == 2) ? 1 : 0;
	data->altitude += (key == 0) ? 1 : 0;
	data->zoom += (key == 69) ? 20 : 0;
	if (key == 78)
		data->zoom -= (data->zoom > 0) ? 20 : 0;
	if (key == 49)
		data->thrd = !data->thrd;
	if (key == 83)
		data->new_color = 0xff0000;
	if (key == 84)
		data->new_color = 0x2edd17;
	if (key == 85)
		data->new_color = 0x0000ff;
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf *data;

	data = (t_fdf*)malloc(sizeof(t_fdf));
	data->altitude = 1;
	data->shift_x = 0;
	data->shift_y = 0;
	data->thrd = 1;
	data->new_color = 0xffae42;
	read_file(av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
