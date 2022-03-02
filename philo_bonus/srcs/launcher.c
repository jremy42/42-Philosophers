/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:39:24 by jremy             #+#    #+#             */
/*   Updated: 2022/03/02 18:34:59 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	__launcher_threads(t_global *global)
{
	int			i;
	pid_t		pid;

	i = 0;
	sem_wait(global->launcher);
	while (i < global->number_of_philo)
	{
		pid = fork();
		if (pid < 0)
			return (0);
		if (pid == 0)
		{
			__routine(global);
			return (2);
		}
		else
		{
			i++;
			global->index_philo++;
		}
	}
	sem_post(global->launcher);
	while (waitpid(-1, NULL, 0) > 0)
		;
	return (1);
}
