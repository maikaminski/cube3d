/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:11:20 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:26:31 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;
	const char	*temps;

	len = 0;
	temps = s;
	while (*temps != '\0')
	{
		temps++;
		len++;
	}
	return (len);
}
