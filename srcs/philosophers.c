/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:58:18 by jremy             #+#    #+#             */
/*   Updated: 2022/02/22 12:57:22 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void *func1(void *arg)
{
    int i;

    i = 0;

    while(1);
    while (i < 10)
    {
        sleep(1);
        printf(RED"thread1 = %s\n"RESET, (char *)arg);
        i++;
    }
    pthread_exit(NULL);
}

void *func2(void *arg)
{
    int i;

    i = 0;

    while (i < 10)
    {
        sleep(2);
        printf(CYAN"thread2 = %s\n"RESET, (char *)arg);
        i++;
    }
    pthread_exit(NULL);
}


int main (int ac, char **av)
{
    pthread_t t1;
    pthread_t t2;

    /*
    creer le mutex dans la struct;
    nbr de philo
    
    */
    (void)av;
    (void)ac;

    pthread_create(&t1, NULL, func1, "toto");
    pthread_create(&t2, NULL, func2, "tata");
    sleep(1);
    pthread_cancel(t1);
    // attend le thread
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return (0);
}