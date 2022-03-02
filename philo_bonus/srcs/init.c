/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:33:50 by jremy             #+#    #+#             */
/*   Updated: 2022/03/02 12:01:07 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
		i++;
	}
	return (1);
}

int	__init_sem(t_global *global)
{
	sem_unlink("forks");
	global->fork = sem_open("forks", O_CREAT, 0644, global->number_of_philo);
	if (global->fork == SEM_FAILED)
		return (0);
	sem_unlink("death");
	global->death = sem_open("death", O_CREAT, 0644, 1);
	if (global->death == SEM_FAILED)
		return (0);
	sem_unlink("print");
	global->print = sem_open("print", O_CREAT, 0644, 1);
	if (global->print == SEM_FAILED)
		return (0);
	global->launcher = sem_open("launcher", O_CREAT, 0644, 1);
	if (global->launcher == SEM_FAILED)
		return (0);
	return (1);
}

int	__init_philo(t_global *global, int ac)
{
	int	i;

	i = 0;
	global->philo = malloc(sizeof(t_philo) * global->number_of_philo);
	if (!global->philo)
		return (__putstr_fd("Malloc Error\n", 2), 0);
	if (!__init_fork(global))
		return (free(global->philo), __putstr_fd("Malloc Error\n", 2), 0);
	while (i < global->number_of_philo)
	{
		memset(&global->philo[i], 0, sizeof(t_philo));
		global->philo[i].l_fork = i;
		global->philo[i].r_fork = (i + 1) % global->number_of_philo;
		global->philo[i].state = THINK;
		global->philo[i].number = i;
		global->philo[i].last_eat = 0;
		if (ac == 6 && global->max_eat >= 0)
			global->philo[i].eat_counter = global->max_eat;
		else
			global->philo[i].eat_counter = -1;
		global->philo[i].ph_global = (void *)global;
		i++;
	}
	return (1);
}

int	__init_global(int ac, char **av, t_global **global)
{
	t_global	*new;

	new = malloc(sizeof(t_global));
	if (!new)
		return (0);
	memset(new, 0, sizeof(t_global));
	if (!__atol(av[1], &(new)->number_of_philo))
		return (free(new), __putstr_fd("Wrong input in number philo\n", 2), 0);
	if (!__atol(av[2], &(new)->time_to_die))
		return (free(new), __putstr_fd("Please give me a valid input\n", 2), 0);
	if (!__atol(av[3], &(new)->time_to_eat))
		return (free(new), __putstr_fd("Please give me a valid input\n", 2), 0);
	if (!__atol(av[4], &(new)->time_to_sleep))
		return (free(new), __putstr_fd("Please give me a valid input \n", 2), 0);
	if (ac == 6)
		if (!__atol(av[5], &(new)->max_eat))
			return (free(new), __putstr_fd("Please give me a digit\n", 2), 0);
	if (!__check_data(new))
		return (free(new), 0);
	if (!__init_philo(new, ac))
		return (free(new), 0);
	if (!__init_sem(new))
		return (free(new), 0);
	*global = new;
	return (1);
}
