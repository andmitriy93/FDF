/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:30:01 by dmian             #+#    #+#             */
/*   Updated: 2019/10/08 18:21:03 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**memory_giver(char const *str, char c)
{
	char	**res;
	int		letters;
	int		i;
	int		j;

	if (!(res = (char **)malloc(sizeof(char*) * (ft_countwords(str, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			letters++;
			i++;
		}
		if (letters > 0)
			if ((res[j++] = (char*)malloc(sizeof(char) * letters + 1)) == NULL)
				return (NULL);
	}
	res[j] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**newstr;
	int		i;
	int		j;
	int		k;
	int		len;

	if (s == NULL)
		return (NULL);
	newstr = memory_giver(s, c);
	len = ft_countwords(s, c);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (k < len)
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i] != c && s[i])
			newstr[k][j++] = s[i++];
		newstr[k][j] = '\0';
		k++;
	}
	return (newstr);
}
