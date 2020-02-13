/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 02:28:07 by dmian             #+#    #+#             */
/*   Updated: 2019/10/07 23:31:12 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	ptr = (char*)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
