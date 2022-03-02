/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:58:18 by jremy             #+#    #+#             */
/*   Updated: 2022/03/02 12:07:17 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	__exit(char *error, t_global *global, int ret)
{
	if (error)
		__putstr_fd(error, 2);
	if (global)
	{
		if (global->philo)
			free(global->philo);
		if (global->tab_fork)
			free(global->tab_fork);
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
	if (!__launcher_threads(global))
		return (__exit("launcher problems !!\n", global, 1));
	__exit("", global, 0);
	sem_close(global->fork);
	sem_unlink("forks");
	sem_close(global->death);
	sem_unlink("death");
	sem_close(global->print);
	sem_unlink("print");
	return (0);
}
