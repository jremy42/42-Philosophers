/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:58:18 by jremy             #+#    #+#             */
/*   Updated: 2022/03/02 18:34:48 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	__sem_close(char *name, sem_t *sem)
{
	if (sem)
	{
		sem_close(sem);
		sem_unlink(name);
	}
}

int	__exit(char *error, t_global *global, int ret)
{
	if (error)
		__putstr_fd(error, 2);
	__sem_close("forks", global->fork);
	__sem_close("death", global->death);
	__sem_close("print", global->print);
	__sem_close("launcher", global->launcher);
	if (global)
	{
		if (global->philo)
			free(global->philo);
		free(global);
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_global	*global;

	global = NULL;
	if (ac < 5 || ac > 6)
		return (__exit("wrong argument\n", NULL, 1));
	if (!__init_global(ac, av, &global))
	{
		return (__exit(NULL, global, 1));
	}
	if (__launcher_threads(global) == 2)
		return (__exit("", global, 1));
	return (__exit("", global, 0));
}
