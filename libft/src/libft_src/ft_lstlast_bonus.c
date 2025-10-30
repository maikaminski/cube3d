/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:06:09 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:24:47 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr_lst;

	if (!lst)
		return (NULL);
	ptr_lst = lst;
	while (ptr_lst->next != NULL)
	{
		ptr_lst = ptr_lst->next;
	}
	return (ptr_lst);
}
