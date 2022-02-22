/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   __isalnum.c   :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: jremy <jremy@student.42.fr>+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2021/11/23 15:56:43 by jremy #+##+# */
/*   Updated: 2022/01/10 15:04:51 by jremy###   ########.fr   */
/**/
/* ************************************************************************** */

#include "libft.h"

int	__isalnum(int c)
{
	if (__isalpha(c) || __isdigit(c))
		return (1);
	return (0);
}
