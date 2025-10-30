/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarol9 <ancarol9@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:13:40 by ancarol9          #+#    #+#             */
/*   Updated: 2025/01/08 20:24:35 by ancarol9         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*hold;

	if (lst && *lst && del)
	{
		while (*lst)
		{
			hold = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = hold;
		}
	}
	*lst = NULL;
}
