/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:13:37 by jremy             #+#    #+#             */
/*   Updated: 2022/03/03 12:04:06 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

int	__print_message(t_state s, t_global *global, t_philo *philo)
{
	if (s == DIE)
		usleep(150);
	if (global->death->__align == 1)
	{
		sem_wait(global->print);
		printf("%ld %d %s\n", (__get_time() - global->start), philo->number + 1,
			__get_message(s));
		sem_post(global->print);
		return (1);
	}
	return (0);
}
