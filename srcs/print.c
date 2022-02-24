/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:13:37 by jremy             #+#    #+#             */
/*   Updated: 2022/02/24 10:46:23 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

char * __get_message(t_state state)
{
    if (state == L_FORK)
        return (" taken a left fork");
    if (state == R_FORK)
        return (" taken a right fork");
    if (state == EAT)
        return (" is eating");
    if (state == SLEEP)
        return (" is sleeping");
     if (state == THINK)
        return (" is thinking");
    return ("");
}

void __print_message(t_state state, int philo, size_t start, pthread_mutex_t print)
{
    pthread_mutex_lock(&print);
    printf("[%ld] Philo -%d- %s\n",(__get_time() - start) , philo + 1, __get_message(state));
    pthread_mutex_unlock(&print);
}