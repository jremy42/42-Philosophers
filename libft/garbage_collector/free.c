/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:31:34 by jremy             #+#    #+#             */
/*   Updated: 2022/02/08 17:03:58 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int __is_in_stack(void *ptr, size_t list_nbr)
{
	t_list	**lst;
	t_list	*tmp;

	tmp = NULL;
	lst = __malloc(0, list_nbr);
	tmp = (*lst);
	if (!tmp || list_nbr == 0)
		return (0);
	while(tmp)
	{
		if (tmp->content == ptr)
			return (1);
		tmp = tmp->next;
	}
	return(0);
}

static size_t lst_memory(void *addr)
{
	size_t stack;

	stack = 0;
	while (stack < MALLOC_LIST)
	{
		if (__is_in_stack(addr, stack))
			return (stack);
		stack++;
	}
	return (stack);
}

int	__free(void	*addr)
{
	size_t	stack;

	stack = lst_memory(addr);
	if (!stack)
		return (free(addr), 0);
	__list_remove(__malloc(0, stack), addr);
	return (1);
}