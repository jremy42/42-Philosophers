/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremy <jremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:58:25 by jremy             #+#    #+#             */
/*   Updated: 2022/02/22 18:34:54 by jremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define RESET   "\033[0m"
# define BLACK   "\033[30m"      /* Black */
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# define MAGENTA "\033[35m"      /* Magenta */
# define CYAN    "\033[36m"      /* Cyan */
# define WHITE   "\033[37m"      /* White */
# define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
# define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
# define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
# define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
# define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

# define __SUCCESS 1
# define __FAIL 0

typedef enum s_state
{ DIE, EAT, SLEEP, THINK} t_state;

typedef enum s_fork
{BUSY, FREE} t_fork;

typedef struct s_philo
{
    t_fork  l_fork;
    t_fork  r_fork;
    t_state state;
    int     number;
    int     eat_counter;
    
} t_philo;

typedef struct s_global
{
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int max_eat;
    int ret_value;
    pthread_mutex_t *fork;
    t_philo **philo;
} t_global;

void	__putstr_fd(char const *s, int fd);
size_t	__strlen(const char *str);
int     __atoi(const char *nb);
int     __atol(const char *nb, int *res);
int     __init_global(int ac, char **av, t_global *global);
int     __launcher_threads(t_global *global);
#endif