/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:46:22 by jremy             #+#    #+#             */
/*   Updated: 2022/02/24 16:52:23 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void __sleeping(t_philo *philo, t_global *global)
{
    (void)global;
    if (__get_time() == philo->end_sleep)
        philo->state = THINK;
}

void __eating(t_philo *philo, t_global *global)
{
    if (__get_time() == philo->end_eat)
    {
        philo->pl_fork = 0;
        philo->pl_fork = 0;
        pthread_mutex_lock(&global->check);
        global->tab_fork[philo->l_fork].busy = 0;
        global->tab_fork[philo->l_fork].busy = 0;
        pthread_mutex_unlock(&global->check);
        pthread_mutex_unlock(&global->tab_fork[philo->l_fork].fork);
        pthread_mutex_unlock(&global->tab_fork[philo->r_fork].fork);
         philo->state = SLEEP;
        __print_message(SLEEP, philo->number, global->start, philo->print);
        philo->last_eat = __get_time();
        philo->end_sleep = __get_time() + (size_t)global->time_to_sleep;
    }
}

void __try_to_eat(t_philo *philo, t_global *global)
{
    if (!philo->pl_fork && !global->tab_fork[philo->l_fork].busy )
    {
        pthread_mutex_lock(&global->check);
        pthread_mutex_lock(&global->tab_fork[philo->l_fork].fork);
        __print_message(L_FORK, philo->number, global->start,philo->print);
        global->tab_fork[philo->l_fork].busy = 1;
        philo->pl_fork = 1;
        pthread_mutex_unlock(&global->check);
    }
    if (!philo->pr_fork && !global->tab_fork[philo->r_fork].busy)
    {
        pthread_mutex_lock(&global->check);
        pthread_mutex_lock(&global->tab_fork[philo->r_fork].fork);
        __print_message(R_FORK, philo->number, global->start,philo->print);
        global->tab_fork[philo->r_fork].busy = 1;
        philo->pl_fork = 1;
        pthread_mutex_unlock(&global->check);
    }
    if(philo->pl_fork && philo->pr_fork)
    {
        philo->state = EAT;
        __print_message(EAT, philo->number, global->start, philo->print);
        philo->last_eat = __get_time();
        philo->end_eat = __get_time() + (size_t)global->time_to_eat;
    }
}