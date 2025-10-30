/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:16:51 by ancarol9          #+#    #+#             */
/*   Updated: 2025/02/20 18:49:31 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*output;
	size_t	i;

	i = 0;
	output = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!output)
		return (NULL);
	while (s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		output[i] = *s2;
		i++;
		s2++;
	}
	output[i] = '\0';
	return (output);
}

int	gnl_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	if (*str == (char)c)
		return (1);
	return (0);
}
