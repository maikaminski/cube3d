/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:33:18 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:09:50 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_switch_case(char str, va_list args)
{
	int	counter;

	counter = 0;
	if (str == 'c')
		counter += pf_putchar_fd(va_arg(args, int), 1);
	else if (str == 's')
		counter += pf_putstr_fd(va_arg(args, char *), 1);
	else if (str == 'p')
		counter += pf_putptr_fd(va_arg(args, void *), 1);
	else if (str == 'd' || str == 'i')
		counter += pf_putnbr_fd(va_arg(args, int), 1);
	else if (str == 'u')
		counter += pf_putunnbr_fd(va_arg(args, unsigned int), 1);
	else if (str == 'x')
		counter += pf_puthex_upper(va_arg(args, unsigned int), 0, 1);
	else if (str == 'X')
		counter += pf_puthex_upper(va_arg(args, unsigned int), 1, 1);
	else if (str == '%')
		counter += pf_putchar_fd('%', 1);
	else
		counter += pf_putchar_fd(str, 1);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, str);
	counter = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter += ft_switch_case(str[i], args);
		}
		else
			counter += pf_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (counter);
}
