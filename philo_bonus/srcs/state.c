/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:46:22 by jremy             #+#    #+#             */
/*   Updated: 2022/03/03 16:47:58 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	__sleeping(t_philo *philo, t_global *global)
{	
	usleep(100);
	if (__get_time() >= philo->end_sleep)
	{
		philo->state = THINK;
		__print_message(THINK, global, philo);
		if (global->number_of_philo == 3)
			__usleep((size_t)(global->time_to_eat * 2 - global->time_to_sleep));
	}
}

void	__eating(t_philo *philo, t_global *global)
{
	usleep(100);
	if (__get_time() >= philo->end_eat)
	{
		philo->pl_fork = 0;
		philo->pr_fork = 0;
		sem_post(global->fork);
		sem_post(global->fork);
		philo->state = SLEEP;
		__print_message(SLEEP, global, philo);
		philo->end_sleep = __get_time() + (size_t)global->time_to_sleep;
	}
}

void	__take_left_fork(t_philo *philo, t_global *global)
{
	if (global->fork->__align > 1)
	{
		if (!philo->pl_fork)
		{
			__print_message(L_FORK, global, philo);
			sem_wait(global->fork);
			philo->pl_fork = 1;
		}
		if (philo->pl_fork && !philo->pr_fork)
		{
			__print_message(R_FORK, global, philo);
			sem_wait(global->fork);
			philo->pr_fork = 1;
		}
	}
}

void	__try_to_eat(t_philo *philo, t_global *global)
{
	usleep(100);
	__take_left_fork(philo, global);
	if (philo->pl_fork && philo->pr_fork)
	{
		philo->state = EAT;
		if (philo->eat_counter > 0)
			philo->eat_counter--;
		__print_message(EAT, global, philo);
		philo->last_eat = __get_time();
		philo->end_eat = __get_time() + (size_t)global->time_to_eat;
	}
}
