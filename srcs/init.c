/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:33:50 by jremy             #+#    #+#             */
/*   Updated: 2022/02/22 18:56:55 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int __check_data(t_global *global)
{
	if (global->number_of_philo <= 2 || global->number_of_philo > 200)
		return (__putstr_fd("wrong number of philo\n", 2), 0);
	if (global->time_to_die < 0)
		return (__putstr_fd("Time to die is negative number\n", 2), 0);
	if (global->time_to_eat < 0)
		return (__putstr_fd("Time to eat is negative number\n", 2), 0);
	if (global->time_to_sleep < 0)
		return (__putstr_fd("Time to sleep is negative number\n", 2), 0);
	return (1);
}

int __init_fork(t_global *global)
{
    int i;

    i = 0;
    
    global->fork = malloc(sizeof(pthread_mutex_t) * global->number_of_philo);
    if (!global->fork)
        return (0);
    while ( i < global->number_of_philo)
    {
        pthread_mutex_init(&global->fork[i], NULL);
        i++;
    }
    return (1);
}

int __init_philo(t_global *global)
{
	int i;

	i = 0;

    __init_fork(global);
    // attention ordre de recuperation des fourchettes
	global->philo = malloc(sizeof(t_philo) * global->number_of_philo);
	if (!global->philo)
		return (0);
	while (i < global->number_of_philo)
	{
		global->philo[i] = malloc(sizeof(t_philo));
		global->philo[i]->l_fork = FREE;
		global->philo[i]->r_fork = FREE;
		global->philo[i]->state = THINK;
        global->philo[i]->number = i;
		global->philo[i]->eat_counter = global->max_eat;
		i++;
	}
	return (1);
}

int __init_global(int ac, char **av, t_global *global)
{
    global->ret_value = 0;
    if (!__atol(av[1], &(global)->number_of_philo))
        return (__putstr_fd("Wrong input in number philo\n", 2), 0);
    if (!__atol(av[2], &(global)->time_to_die))
        return (__putstr_fd("Please give me a valid input\n", 2), 0);
    if (!__atol(av[3], &(global)->time_to_eat))
        return (__putstr_fd("Please give me a valid input\n", 2), 0);
    if (!__atol(av[4], &(global)->time_to_sleep))
        return (__putstr_fd("Please give me a valid input \n", 2), 0);
    if (ac == 6)
    {
        if (!__atol(av[5], &(global)->max_eat))
        return (__putstr_fd("Please give me a digit\n", 2), 0);
    }
    else
	{
        global->max_eat = 0;
	}
	if (!__check_data(global))
		return (0);
	if (!__init_philo(global))
		return (0);
    return (1);
}