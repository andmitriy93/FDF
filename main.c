/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:52:35 by dmian             #+#    #+#             */
/*   Updated: 2020/02/12 16:46:38 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		dest_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int		main(int argc, char **argv)
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);

	int	i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
