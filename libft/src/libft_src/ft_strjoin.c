/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:03:53 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:23:32 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	len1;
	size_t	len2;
	size_t	total;

	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	total = len1 + len2;
	output = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!output)
		return (NULL);
	ft_memset(output, 0, total + 1);
	if (s1 != NULL)
		ft_strlcat(output, s1, len1 + 1);
	if (s2 != NULL)
		ft_strlcat(output, s2, len1 + len2 + 1);
	return (output);
}
