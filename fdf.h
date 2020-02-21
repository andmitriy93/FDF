/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:23:36 by dmian             #+#    #+#             */
/*   Updated: 2020/02/20 18:21:53 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>

typedef	struct
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	double		altitude;
	bool		thrd;
	int			new_color;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef	struct
{
	float		y;
	float		x;
	int			z;
}				t_coord;

void			read_file(char *file_name, t_fdf *data);
void			bresenham(t_coord dota, t_coord dotb, t_fdf *data);
void			draw(t_fdf *data);
float			mod(float i);
float			max(float x, float y);
void			threedimensional(t_coord	*thrd, t_coord *thrd2);
void			ft_zooming(t_coord	*dota, t_coord *dotb, t_fdf *data);
void			ft_shift(t_coord	*dota, t_coord *dotb, t_fdf *data);
void			altitude(t_coord	*dota, t_coord *dotb, t_fdf *data);

#endif
