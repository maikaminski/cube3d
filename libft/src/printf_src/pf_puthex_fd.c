/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:31:45 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:08:19 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	pf_puthex_fd(unsigned long n, char *base, int fd)
{
	char			output[16];
	int				counter;
	int				len;

	counter = 0;
	len = 0;
	if (!n)
		return (pf_putchar_fd('0', fd));
	while (n > 0)
	{
		output[len++] = base[n % 16];
		counter++;
		n /= 16;
	}
	while (--len >= 0)
		pf_putchar_fd(output[len], fd);
	return (counter);
}

int	pf_puthex_upper(unsigned int n, int uppercase, int fd)
{
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	if (uppercase)
		return (pf_puthex_fd(n, upper, fd));
	else
		return (pf_puthex_fd(n, lower, fd));
}

int	pf_putptr_fd(void *arg, int fd)
{
	unsigned long	address;
	int				counter;

	counter = 0;
	address = (unsigned long)arg;
	if (!arg)
		return (pf_putstr_fd("(nil)", fd));
	counter += pf_putstr_fd("0x", fd);
	counter += pf_puthex_fd(address, "0123456789abcdef", fd);
	return (counter);
}
