/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:20:11 by dmian             #+#    #+#             */
/*   Updated: 2020/02/17 18:28:32 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_read_line(char **str, char **line, int fd)
{
	char	*tmp;
	int		count;

	count = 0;
	while (str[fd][count] != '\0' && str[fd][count] != '\n')
		count++;
	*line = ft_strsub(str[fd], 0, count);
	if (str[fd][count] == '\n')
	{
		tmp = ft_strdup(&str[fd][count + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
		ft_strdel(&str[fd]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[256];
	int				byte;
	char			*tmp;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	while ((byte = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (str[fd] == NULL && byte == 0)
		return (0);
	return (ft_read_line(str, line, fd));
}
