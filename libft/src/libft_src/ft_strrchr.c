/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:07:20 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:26:47 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr_s;

	ptr_s = (char *)s;
	ptr_s += ft_strlen(ptr_s);
	while (ptr_s >= s)
	{
		if (*ptr_s == (char)c)
			return (ptr_s);
		ptr_s--;
	}
	if (c == '\0')
		return (ptr_s);
	return (NULL);
}
