/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:39:24 by jremy             #+#    #+#             */
/*   Updated: 2022/03/02 09:34:30 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	__launcher_threads(t_global *global)
{
	int			i;
	pthread_t	*tid;

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
	while (i < global->number_of_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (free(tid), 1);
}
