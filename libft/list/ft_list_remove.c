/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   __lstadd_back.c   :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: jremy <jremy@student.42.fr>+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2021/11/23 18:58:14 by jremy #+##+# */
/*   Updated: 2022/01/10 15:04:51 by jremy###   ########.fr   */
/**/
/* ************************************************************************** */

#include "libft.h"

void __list_remove(t_list **lst, void *addr)
{
	t_list *tmp;
	t_list *remove;

	tmp = (*lst);

	while(tmp->next->content != addr)
		tmp = tmp->next;
	remove = tmp->next;
	if (tmp->next->next)
		tmp->next = tmp->next->next;
	free(addr);
	free(remove);
}