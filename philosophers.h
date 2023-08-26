/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:12:01 by razasharuku       #+#    #+#             */
/*   Updated: 2023/08/23 10:21:23 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
#  define NUM_THREADS 10
#   define TIMEVAL_TO_TIMESPEC(tv, ts) { \
		(ts)->tv_sec = (tv)->tv_sec; \
		(ts)->tv_nsec = (tv)->tv_usec * 1000; \
}


typedef struct s_timeval
{
	time_t tv_sec;
	suseconds_t tv_usec;
}			t_timeval;

typedef struct s_philo
{
	int	Number_of_philosophers;
	int	Time_to_die;
	int	Time_to_eat;
	int	Time_to_sleep;
	int	Num_of_times_each_philo_must_eat;
}				t_philo;


#endif