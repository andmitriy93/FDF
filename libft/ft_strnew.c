/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:16:15 by dmian             #+#    #+#             */
/*   Updated: 2019/09/25 15:09:17 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *temp;

	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (temp == NULL)
		return (NULL);
	while (size > 0)
	{
		temp[size] = '\0';
		size--;
	}
	temp[0] = '\0';
	return (temp);
}
