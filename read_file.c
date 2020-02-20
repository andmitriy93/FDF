/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:26:16 by dmian             #+#    #+#             */
/*   Updated: 2020/02/19 14:41:38 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int     get_height(char *file_name)
{
    char    *line;
    int     fd;
    int     height;

    fd = open(file_name, O_RDONLY, 0);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int     get_width(char *file_name)
{
    int     width;
    int     fd;
    char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_countwords(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int	*z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int**)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
}
