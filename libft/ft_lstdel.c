/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 12:06:51 by dmian             #+#    #+#             */
/*   Updated: 2019/10/04 12:11:44 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *lnext;

	if (alst != NULL)
	{
		tmp = *alst;
		lnext = *alst;
		while (tmp != NULL)
		{
			(*del)(tmp->content, tmp->content_size);
			tmp = lnext->next;
			free(lnext);
			lnext = tmp;
		}
		*alst = NULL;
	}
}
