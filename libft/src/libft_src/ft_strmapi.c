/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:11:13 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:26:35 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	size_t	i;

	if (!s)
		return (NULL);
	output = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		output[i] = f(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
