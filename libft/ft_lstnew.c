/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:13:45 by dmian             #+#    #+#             */
/*   Updated: 2019/10/08 19:49:01 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	if ((new_list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content_size = 0;
		new_list->content = NULL;
		new_list->next = NULL;
	}
	else
	{
		if ((new_list->content = malloc(content_size)) == NULL)
		{
			free(new_list);
			return (NULL);
		}
		else
		{
			ft_memcpy(new_list->content, content, content_size);
			new_list->content_size = content_size;
			new_list->next = NULL;
		}
	}
	return (new_list);
}
