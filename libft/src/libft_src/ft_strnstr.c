/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:14:02 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:26:43 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;
	size_t	b;

	b = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[b] != '\0' && b < len)
	{
		if (big[b] == little[0])
		{
			l = 0;
			while (big[b + l] == little[l] && (b + l) < len)
			{
				if (little[l + 1] == '\0')
					return ((char *)big + b);
				l++;
			}
		}
		b++;
	}
	return (NULL);
}
