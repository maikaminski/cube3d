/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:02:21 by ancarol9          #+#    #+#             */
/*   Updated: 2025/03/21 14:59:11 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long	ft_atol(const char *nptr)
{
	long	nb;
	long	isneg;

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
