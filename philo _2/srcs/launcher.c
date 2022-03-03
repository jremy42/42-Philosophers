/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:39:24 by jremy             #+#    #+#             */
/*   Updated: 2022/03/03 17:05:27 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *death(void *send_global)
{
	t_global *global;

	global = (t_global *)send_global;
	int i;

	i = 0;
	while (1)
	{
		if (i = global->ch)
	}
	
}

int	__launcher_threads(t_global *global)
{
	int			i;
	pthread_t	*tid;
	pthread_t	*death;

	tid = malloc(sizeof(pthread_t) * global->number_of_philo);
	if (!tid)
		return (0);
	i = 0;
	pthread_mutex_lock(&global->check);
	while (i < global->number_of_philo)
	{
		if (pthread_create(&tid[i],
				NULL, __routine, (void *)(&global->philo[i])) != 0)
			return (free(tid), 0);
		i++;
	}
	i = 0;
	global->start = __get_time();
	pthread_mutex_unlock(&global->check);
	if (pthread_create(&death,
				NULL, __death, (void *)(&global) != 0)
			return (free(tid), 0);
	while (i < global->number_of_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (free(tid), 1);
}
