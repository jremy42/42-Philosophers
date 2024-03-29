/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:58:18 by jremy             #+#    #+#             */
/*   Updated: 2022/02/28 14:10:20 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	__get_time();
	if (!__init_global(ac, av, &global))
	{
		return (__exit(NULL, global, 1));
	}
	if (!__launcher_threads(global))
		return (__exit("launcher problems !!\n", global, 1));
	__exit("", global, 0);
	return (0);
}
