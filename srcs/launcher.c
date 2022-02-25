/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:39:24 by jremy             #+#    #+#             */
/*   Updated: 2022/02/25 16:20:44 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philo(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->number_of_philo)
	{
		printf("############### number [%d]####################\n", global->philo[i].number);
		printf("l_fork = [%d]\n", global->philo[i].l_fork);
		printf("r_fork = [%d]\n", global->philo[i].r_fork);
		printf("state = [%d]\n", global->philo[i].state);
		printf("eat counter = [%d]\n\n\n",global->philo[i].eat_counter);
		i++;
	}
}

int	__launcher_threads(t_global *global)
{
	int			i;
	pthread_t	*tid;

	tid = malloc(sizeof(pthread_t) * global->number_of_philo);
	i = 0;
	global->start = __get_time();
	while (i < global->number_of_philo)
	{
		if (pthread_create(&tid[i],
				NULL, __routine, (void *)(&global->philo[i])) != 0)
			return (0);
		if (!(global->number_of_philo) % 2)
			__usleep(8);
		else
			__usleep(1);
		i++;
	}
	i = 0;
	while (i < global->number_of_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (1);
}

/*
 pthread_mutex_lock(&(global->fork[0]));
	__usleep(global->time_to_eat);
	pthread_mutex_unlock(&(global->fork[0]));
	printf("############### number [%d]####################\n",philo->number);
	printf("l_fork = [%d]\n", philo->l_fork);
	printf("r_fork = [%d]\n", philo->r_fork);
	printf("state = [%d]\n", philo->state);
	printf("eat counter = [%d]\n\n\n", philo->eat_counter);
*/