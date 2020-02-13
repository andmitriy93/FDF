/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 09:13:05 by dmian             #+#    #+#             */
/*   Updated: 2019/09/27 01:10:49 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;
	int		len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = (*f)(s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
