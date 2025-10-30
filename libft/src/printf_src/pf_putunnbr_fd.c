/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putunnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:46:31 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:09:12 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	pf_putunnbr_fd(unsigned int n, int fd)
{
	int	counter;

	counter = 0;
	if (n >= 10)
		counter += pf_putunnbr_fd(n / 10, fd);
	pf_putchar_fd((n % 10 + '0'), fd);
	counter++;
	return (counter);
}
