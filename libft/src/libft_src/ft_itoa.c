/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:07:23 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:23:53 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_countlen(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		len;
	long	num;

	len = ft_countlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	num = n;
	if (n < 0)
	{
		output[0] = '-';
		num = -n;
	}
	output[len] = '\0';
	while (num > 0)
	{
		output[len-- - 1] = (num % 10) + '0';
		num /= 10;
	}
	return (output);
}
