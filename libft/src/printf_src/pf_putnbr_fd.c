/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:50:28 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:08:43 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	count_len(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num != 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

int	pf_putnbr_fd(int n, int fd)
{
	long	num;
	char	output[12];
	int		len;
	int		i;

	if (n == 0)
		return (pf_putchar_fd('0', fd));
	num = (long)n;
	len = count_len(n);
	i = 0;
	if (num < 0)
	{
		pf_putchar_fd('-', fd);
		num = -num;
	}
	while (num > 0)
	{
		output[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (--i >= 0)
		pf_putchar_fd(output[i], fd);
	return (len);
}
