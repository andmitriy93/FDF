/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:23:36 by dmian             #+#    #+#             */
/*   Updated: 2020/02/12 16:43:39 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef	struct
{
	int width;
	int height;
	int **z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void	read_file(char *file_name, fdf *data);

#endif
