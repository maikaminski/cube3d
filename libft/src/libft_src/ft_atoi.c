/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:51:45 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/10 18:14:11 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	isneg;

	nb = 0;
	isneg = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\r'
		|| *nptr == '\n' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			isneg *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 +(*nptr - 48);
		nptr++;
	}
	return (nb * isneg);
}
