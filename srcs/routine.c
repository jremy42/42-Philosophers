/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:52:35 by jremy             #+#    #+#             */
/*   Updated: 2022/02/24 17:02:17 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int __check_dead(t_global *global)
{
    pthread_mutex_lock(&global->check);
    if(global->death)
    {
        printf("global->death = %d\n", global->death);
        pthread_mutex_unlock(&global->check);
        return (0);
    }
    pthread_mutex_unlock(&global->check);
    return (1);
}

int __should_i_die(t_philo *philo, t_global *global)
{
    //printf("philo dead = %lu\n get_time = %lu\n", philo->last_eat + (size_t)global->time_to_die, __get_time());
    if (philo->last_eat + (size_t)global->time_to_die <= __get_time())
        return (0);
    return (1);
}

int __check_state(t_state state, t_philo *philo, t_global *global)
{
    if(state != EAT)
    {
        if (__should_i_die(philo, global))
        {
            pthread_mutex_lock(&global->check);
            global->death = 1;
            pthread_mutex_unlock(&global->check);
            printf("je dois dead baby\n");
            return (0);    
        }
    }
    if(!__check_dead(global))
        return (0);
    return (1);
}

void *__routine(void *send_philo)
{
    t_philo *philo;
    t_global *global;
    void	(*f_state[4])(t_philo *philo, t_global *global);
    
	f_state[EAT] = __eating;
    f_state[SLEEP] = __sleeping;
    f_state[THINK] = __try_to_eat;
    /*
	f_state[SLEEP]
	f_state[THINK]
	f_state[FORK]
    */
    philo = (t_philo *)send_philo;
    pthread_mutex_lock(&philo->print);
    global = (t_global *)(philo->ph_global);
    pthread_mutex_unlock(&philo->print);
    philo->last_eat = __get_time();
    printf("check = %d\n",__check_state(philo->state, philo, global));
    while(__check_state(philo->state, philo, global))
        f_state[philo->state](philo, global);
    return((void *)1);
}

/*

void __eat(t_philo *philo, pthread_mutex_t *fork, int time_to_eat, size_t start)
{
    pthread_mutex_lock(&fork[philo->l_fork]);
    __print_message(L_FORK, philo->number, start,philo->print);
    pthread_mutex_lock(&fork[philo->r_fork]);
    __print_message(R_FORK, philo->number, start,philo->print);
    __print_message(EAT, philo->number, start, philo->print);
    __usleep(time_to_eat);
    pthread_mutex_unlock(&fork[philo->l_fork]);
    pthread_mutex_unlock(&fork[philo->r_fork]);

}

void *__routine(void *send_philo)
{
    t_philo *philo;
    t_global *global;

    philo = (t_philo *)send_philo;
    pthread_mutex_lock(&philo->print);
    global = (t_global *)(philo->ph_global);
    pthread_mutex_unlock(&philo->print);
    philo->last_eat = __get_time();
    while (__check_dead)
    {
        __eat(philo, global->fork, global->time_to_eat, global->start);
        philo->last_eat = __get_time() + global->time_to_die;
        __print_message(SLEEP, philo->number, global->start, philo->print);
        __usleep(global->time_to_sleep);
        __print_message(THINK, philo->number, global->start, philo->print);
    }
    return ((void *)1);
}
*/