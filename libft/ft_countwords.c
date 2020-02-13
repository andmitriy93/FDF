/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmian <dmian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:48:12 by dmian             #+#    #+#             */
/*   Updated: 2019/10/08 16:17:50 by dmian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countwords(const	char *s, char c)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c)
				i++;
		else if (s[i])
		{
			n++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (n);
}
