/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:53:04 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:25:15 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;

	d_ptr = (unsigned char *)dest;
	s_ptr = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		d_ptr += n;
		s_ptr += n;
		while (n--)
			*(--d_ptr) = *(--s_ptr);
	}
	else
	{
		while (n--)
			*d_ptr++ = *s_ptr++;
	}
	return (dest);
}
