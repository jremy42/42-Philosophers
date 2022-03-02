/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:46:22 by jremy             #+#    #+#             */
/*   Updated: 2022/03/02 10:18:16 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	__sleeping(t_philo *philo, t_global *global)
{	
	if (__get_time() >= philo->end_sleep)
	{
		philo->state = THINK;
		pthread_mutex_lock(&global->check);
		__print_message(THINK, global, philo);
		pthread_mutex_unlock(&global->check);
		return ;
	}
	//__usleep(global->time_to_sleep);
}

void	__eating(t_philo *philo, t_global *global)
{
	if (__get_time() >= philo->end_eat)
	{	
		pthread_mutex_lock(&global->check);
		global->tab_fork[philo->l_fork].busy = 0;
		global->tab_fork[philo->r_fork].busy = 0;
		__print_message(SLEEP, global, philo);
		pthread_mutex_unlock(&global->check);
		philo->state = SLEEP;
		philo->end_sleep = __get_time() + (size_t)global->time_to_sleep;
		philo->pl_fork = 0;
		philo->pr_fork = 0;
	}
}

void	__take_left_fork(t_philo *philo, t_global *global)
{
	pthread_mutex_lock(&global->check);
	if (!philo->pl_fork && !global->tab_fork[philo->l_fork].busy)
	{
		pthread_mutex_lock(&global->tab_fork[philo->l_fork].fork);
		global->tab_fork[philo->l_fork].busy = 1;
		pthread_mutex_unlock(&global->tab_fork[philo->l_fork].fork);
		__print_message(L_FORK, global, philo);
		philo->pl_fork = 1;
	}
	if (philo->pl_fork && !philo->pr_fork
		&& !global->tab_fork[philo->r_fork].busy)
	{
		pthread_mutex_lock(&global->tab_fork[philo->r_fork].fork);
		global->tab_fork[philo->r_fork].busy = 1;
		pthread_mutex_unlock(&global->tab_fork[philo->r_fork].fork);
		__print_message(R_FORK, global, philo);
		philo->pr_fork = 1;
	}
	pthread_mutex_unlock(&global->check);
}

void	__try_to_eat(t_philo *philo, t_global *global)
{
	__take_left_fork(philo, global);
	if (philo->pl_fork && philo->pr_fork)
	{
		philo->state = EAT;
		if (philo->eat_counter > 0)
			philo->eat_counter--;
		pthread_mutex_lock(&global->check);
		__print_message(EAT, global, philo);
		pthread_mutex_unlock(&global->check);
		philo->end_eat = __get_time() + (size_t)global->time_to_eat;
		philo->last_eat = __get_time();
	}
}
