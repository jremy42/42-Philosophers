/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:52:35 by jremy             #+#    #+#             */
/*   Updated: 2022/03/01 12:39:03 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	__check_dead(t_global *global)
{
	//pthread_mutex_lock(&global->check);
	if (global->death)
	{
		//pthread_mutex_unlock(&global->check);
		return (0);
	}
	//pthread_mutex_unlock(&global->check);
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
			//pthread_mutex_lock(&global->check);
			//global->death = 1;
			//pthread_mutex_unlock(&global->check);
			__print_message(DIE, philo->number, global->start, 0);
			return (0);
		}
	}
	if (!__check_dead(global))
		return (0);
	if (state == SLEEP && !philo->eat_counter)
	{
		//pthread_mutex_lock(&global->check);
		global->tab_fork[philo->l_fork].busy = 0;
		global->tab_fork[philo->r_fork].busy = 0;
		//pthread_mutex_unlock(&global->check);
		return (0);
	}
	return (1);
}	

int __routine(t_global *global)
{

	//global->death++;
	printf("\n");
	printf("id = %d\n", global->index_philo);
	sem_post(global->death);
	printf("death = %ld\n", global->death->__align);
	printf("\n");
	printf("\n");

	/*
	t_philo		*philo;
	t_global	*global;
	void		(*f_state[4])(t_philo *philo, t_global *global);

	f_state[EAT] = __eating;
	f_state[SLEEP] = __sleeping;
	f_state[THINK] = __try_to_eat;
	philo = (t_philo *)send_philo;
	philo->last_eat = 0;
	//pthread_mutex_lock(&philo->print);
	global = (t_global *)(philo->ph_global);
	//pthread_mutex_unlock(&philo->print);
	philo->last_eat = __get_time();
	while (__check_state(philo->state, philo, global))
		f_state[philo->state](philo, global);
	*/
	return (0);
}
