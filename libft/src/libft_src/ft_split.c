/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:46:25 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/10 19:46:48 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	sub_counter(const char *str, char c)
{
	int	counter;
	int	in_substr;

	counter = 0;
	in_substr = 0;
	while (*str)
	{
		if (*str != c && !in_substr)
		{
			in_substr = 1;
			counter++;
		}
		else if (*str == c)
			in_substr = 0;
		str++;
	}
	return (counter);
}

static char	*get_next_sbstr(const char **str, char c)
{
	size_t		len;
	char		*substr;
	const char	*start;

	start = *str;
	while (**str && **str != c)
		(*str)++;
	len = *str - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	else
	{
		ft_strlcpy(substr, start, len + 1);
		substr[len] = '\0';
	}
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		counter;
	int		i;

	if (!s)
		return (NULL);
	counter = sub_counter(s, c);
	output = malloc((counter + 1) * sizeof(char *));
	i = 0;
	if (!output)
		return (NULL);
	while (*s)
	{
		if (*s != c)
			output[i++] = get_next_sbstr(&s, c);
		else
			s++;
	}
	output[i] = NULL;
	return (output);
}
