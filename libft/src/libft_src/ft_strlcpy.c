/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:06:31 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:26:28 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size > 0)
	{
		while (src[len] != '\0')
		{
			if (len < size - 1)
			{
				dst[len] = src[len];
			}
			len++;
		}
		if (len < size)
			dst[len] = '\0';
		else
			dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}
