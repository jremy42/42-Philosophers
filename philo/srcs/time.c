/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:02:30 by jremy             #+#    #+#             */
/*   Updated: 2022/03/01 16:01:09 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	__usleep(size_t sleep)
{
	size_t	time;

	time = __get_time() + sleep;
	while (__get_time() < time)
		usleep(100);
}

size_t	__get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((size_t)(time.tv_sec * 1000) + (size_t)(time.tv_usec / 1000));
}
