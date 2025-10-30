/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:31:08 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:26:24 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		d_len;

	i = 0;
	d_len = ft_strlen(dst);
	if (size <= d_len)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && d_len + i + 1 < size)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (ft_strlen(src) + d_len);
}
