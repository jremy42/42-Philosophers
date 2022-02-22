/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:34:06 by jremy             #+#    #+#             */
/*   Updated: 2022/02/09 10:45:01 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*__malloc(size_t size, size_t list_nbr)
{
	static t_list *lst[MALLOC_LIST];
	t_list *new;
	void	*new_addr;

	if (list_nbr > MALLOC_LIST)
		return (NULL);
	if (size == 0)
		return(&lst[list_nbr]);
	new_addr = __calloc(size, 1);
	if (!new_addr)
		return (__lstclear(&lst[list_nbr], free), NULL);
	else
	{
		new = __lstnew(new_addr);
		if (!new)
			return (free(new_addr), NULL);
		__lstadd_front(&lst[list_nbr],new);
	}
	return (new_addr);
}