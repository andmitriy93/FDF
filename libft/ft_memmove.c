/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:39:22 by dmian             #+#    #+#             */
/*   Updated: 2019/10/07 22:48:36 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst >= src)
	{
		while (len--)
		{
			p_dst[len] = p_src[len];
		}
	}
	else
	{
		while (len--)
		{
			*(p_dst++) = *(p_src++);
		}
	}
	return (dst);
}
