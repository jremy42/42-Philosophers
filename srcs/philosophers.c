/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:58:18 by jremy             #+#    #+#             */
/*   Updated: 2022/02/25 10:10:47 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	__exit(char *error, t_global *global, int ret)
{
	if (error)
		__putstr_fd(error, 2);
	if (global)
	{
		if (global->ret_value)
			return (global->ret_value);
		if (global->philo)
			free(global->philo);
		free(global);
	}
	return (ret);
}

int	main (int ac, char **av)
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
	return (0);
}

/*
	pthread_t t1;
	pthread_t t2;

	creer le mutex dans la struct;
	nbr de global
	
	(void)av;
	(void)ac;
	// secure les pthread_create
	pthread_create(&t1, NULL, func1, "toto");
	pthread_create(&t2, NULL, func2, "tata");
	sleep(1);
	pthread_cancel(t1);
	// attend le thread
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
*/