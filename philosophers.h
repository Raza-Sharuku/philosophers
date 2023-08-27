/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:12:01 by razasharuku       #+#    #+#             */
/*   Updated: 2023/08/27 15:43:33 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <pthread.h>
# define NUM_THREADS 10

typedef struct s_timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}			t_timeval;

typedef struct s_info
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	least_time_to_eat;
	int	stop_flag;
	
}				t_info;

typedef struct s_philo
{
	t_info	*info;
	int				id;
	pthread_mutex_t	*my_fork;
	struct s_philo	*next;
	struct s_philo	*prev;

}				t_philo;

int							ft_atoi(const char *str);
t_philo						*make_philo(t_info *info);


#endif