/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:52:35 by jremy             #+#    #+#             */
/*   Updated: 2022/03/01 14:52:25 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	__check_dead(t_global *global)
{
	if (!global->death->__align)
		return (0);
	return (1);
}

int	__should_i_die(t_philo *philo, t_global *global)
{
	if (__get_time() >= (philo->last_eat + (size_t)global->time_to_die))
		return (1);
	return (0);
}

int	__check_state(t_state state, t_philo *philo, t_global *global)
{
	if (state != EAT)
	{
		if (__should_i_die(philo, global))
		{
			sem_wait(global->death);
			__print_message(DIE, philo->number, global->start, 0);
			return (0);
		}
	}
	if (!__check_dead(global))
		return (0);
	if (state == SLEEP && !philo->eat_counter)
	{
		sem_post(global->fork);
		sem_post(global->fork);
		return (0);
	}
	return (1);
}	

int __routine(t_global *global)
{
	t_philo		*philo;
	void		(*f_state[4])(t_philo *philo, t_global *global);

	f_state[EAT] = __eating;
	f_state[SLEEP] = __sleeping;
	f_state[THINK] = __try_to_eat;
	philo = &global->philo[global->index_philo];
	philo->last_eat = 0;
	philo->last_eat = __get_time();
	while (__check_state(philo->state, philo, global))
		f_state[philo->state](philo, global);
	return (0);
}
