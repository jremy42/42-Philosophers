/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:39:24 by jremy             #+#    #+#             */
/*   Updated: 2022/02/22 19:05:08 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void print_philo(t_global *global)
{
    int i;

    i = 0;
    while(global->philo[i])
    {
        printf("############### number [%d]####################\n",global->philo[i]->number);
		printf("l_fork = [%d]\n",global->philo[i]->l_fork);
        printf("r_fork = [%d]\n",global->philo[i]->r_fork);
        printf("state = [%d]\n",global->philo[i]->state);
	    printf("eat counter = [%d]\n\n\n",global->philo[i]->eat_counter);
        i++;
    }
}

void *__routine(void *send_philo)
{
    t_philo *philo;

    philo = (t_philo *)send_philo;
    printf("############### number [%d]####################\n",philo->number);
	printf("l_fork = [%d]\n", philo->l_fork);
    printf("r_fork = [%d]\n", philo->r_fork);
    printf("state = [%d]\n", philo->state);
	printf("eat counter = [%d]\n\n\n", philo->eat_counter);
    return ((void *)1);
}

int __launcher_threads(t_global *global)
{
    //print_philo(global);
    int i;
    pthread_t tid;
    
    i = 0;
    while(global->philo[i])
    {
        if ( pthread_create(&tid, NULL, __routine, (void *)(global->philo[i])) != 0)
            return (0);
        usleep(500);
        //attention usleep
        i++;
    }
    //sleep(5);
    return (1);
}