/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:33:50 by jremy             #+#    #+#             */
/*   Updated: 2022/02/25 10:41:23 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	__check_data(t_global *global)
{
	if (global->number_of_philo <= 0 || global->number_of_philo > 200)
		return (__putstr_fd("wrong number of philo\n", 2), 0);
	if (global->time_to_die < 0)
		return (__putstr_fd("Time to die is negative number\n", 2), 0);
	if (global->time_to_eat < 0)
		return (__putstr_fd("Time to eat is negative number\n", 2), 0);
	if (global->time_to_sleep < 0)
		return (__putstr_fd("Time to sleep is negative number\n", 2), 0);
	return (1);
}

int	__init_fork(t_global *global)
{
	int	i;

	i = 0;
	global->tab_fork = malloc(sizeof(t_fork) * global->number_of_philo);
	if (!global->tab_fork)
		return (0);
	while (i < global->number_of_philo)
	{
		global->tab_fork[i].busy = 0;
		pthread_mutex_init(&global->tab_fork[i].fork, NULL);
		i++;
	}
	return (1);
}

int	__init_philo(t_global *global)
{
	int	i;

	i = 0;
	if (!__init_fork(global))
		return (__putstr_fd("Malloc Error\n", 2), 0);
	global->philo = malloc(sizeof(t_philo) * global->number_of_philo);
	if (!global->philo)
		return (__putstr_fd("Malloc Error\n", 2), 0);
	while (i < global->number_of_philo)
	{
		memset(&global->philo[i], 0, sizeof(t_philo));
		global->philo[i].l_fork = i;
		global->philo[i].r_fork = (i + 1) % global->number_of_philo;
		global->philo[i].state = THINK;
		global->philo[i].number = i;
		global->philo[i].eat_counter = global->max_eat;
		global->philo[i].ph_global = (void *)global;
		pthread_mutex_init(&global->philo[i].print, NULL);
		i++;
	}
	return (1);
}

int	__init_global(int ac, char **av, t_global **global)
{
	t_global	*new;

	new = malloc(sizeof(t_global));
	memset(new, 0, sizeof(t_global));
	new->ret_value = 0;
	if (!__atol(av[1], &(new)->number_of_philo))
		return (__putstr_fd("Wrong input in number philo\n", 2), 0);
	if (!__atol(av[2], &(new)->time_to_die))
		return (__putstr_fd("Please give me a valid input\n", 2), 0);
	if (!__atol(av[3], &(new)->time_to_eat))
		return (__putstr_fd("Please give me a valid input\n", 2), 0);
	if (!__atol(av[4], &(new)->time_to_sleep))
		return (__putstr_fd("Please give me a valid input \n", 2), 0);
	if (ac == 6)
		if (!__atol(av[5], &(new)->max_eat))
			return (__putstr_fd("Please give me a digit\n", 2), 0);
	if (!__check_data(new))
		return (0);
	if (!__init_philo(new))
		return (0);
	new->death = 0;
	new->start = 0;
	pthread_mutex_init(&new->check, NULL);
	*global = new;
	return (1);
}
