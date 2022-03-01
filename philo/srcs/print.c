/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:13:37 by jremy             #+#    #+#             */
/*   Updated: 2022/03/01 15:50:54 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char	*__get_message(t_state state)
{
	if (state == L_FORK)
		return ("has taken a fork");
	if (state == R_FORK)
		return ("has taken a fork");
	if (state == EAT)
		return ("is eating");
	if (state == SLEEP)
		return ("is sleeping");
	if (state == THINK)
		return ("is thinking");
	if (state == DIE)
		return ("died");
	return ("");
}

void	__print_message(t_state s, t_global *global, t_philo *philo)
{
		pthread_mutex_lock(&philo->print);
		printf("%ld %d %s\n", (__get_time() - global->start), philo->number + 1,
			__get_message(s));
		pthread_mutex_unlock(&philo->print);
}
