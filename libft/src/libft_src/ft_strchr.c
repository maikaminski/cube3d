/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:07:20 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:26:11 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	ptr_s = (char *)s;
	while (*ptr_s)
	{
		if (*ptr_s == (unsigned char)c)
			return (ptr_s);
		ptr_s++;
	}
	if ((unsigned char)c == '\0')
		return (ptr_s);
	return (NULL);
}
