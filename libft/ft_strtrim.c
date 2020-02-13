/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:19:43 by dmian             #+#    #+#             */
/*   Updated: 2019/10/08 15:46:02 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		trim_str_len(const char *s)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	while ((s[start] == '\n' || s[start] == '\t' || \
		s[start] == ' ') && s[start] != '\0')
		start++;
	end = ft_strlen(s) - 1;
	while ((s[end] == '\n' || s[end] == '\t' || \
		s[end] == ' ') && s[start] != '\0')
		end--;
	len = (end - start) + 1;
	return (len);
}

char				*ft_strtrim(const char *s)
{
	char		*ptr;
	size_t		i;
	size_t		len;

	len = 0;
	ptr = NULL;
	if (s)
	{
		len = trim_str_len(s);
		if (!(ptr = (char*)malloc(len + 1)))
			return (NULL);
		i = 0;
		while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
			s++;
		while (i < len)
		{
			ptr[i] = s[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
