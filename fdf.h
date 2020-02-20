/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:23:36 by dmian             #+#    #+#             */
/*   Updated: 2020/02/20 15:49:52 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef	struct
{
	int 	width;
	int 	height;
	int 	**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

typedef	struct
{
	float	y;
	float	x;
	int		z;
	
}			coord;

void	read_file(char *file_name, fdf *data);
void	bresenham(coord dotA, coord dotB, fdf *data);
void	draw(fdf *data);
float	mod(float i);
float	max(float x, float y);

#endif
