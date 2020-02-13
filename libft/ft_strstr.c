/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:57:37 by dmian             #+#    #+#             */
/*   Updated: 2019/09/25 12:51:30 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		n = i;
		while (haystack[n] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
			n++;
		}
		i++;
	}
	return (0);
}
