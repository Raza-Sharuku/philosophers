/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:12:01 by razasharuku       #+#    #+#             */
/*   Updated: 2023/09/02 20:31:27 by sraza            ###   ########.fr       */
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
# include <stdatomic.h>
# define NUM_THREADS 10

typedef struct s_timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}			t_timeval;

typedef struct s_info
{
	int			num_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			least_time_to_eat;
	time_t		start_time;
	atomic_int	stop_flag;
	pthread_t	moniter;
	t_philo		*philo;
}				t_info;

typedef struct s_philo
{
	t_info			*info;
	pthread_t		thread;
	int				id;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	*side_fork;
	atomic_int		eat_count;
	atomic_long		last_time_of_eat;
	struct s_philo	*next;
	struct s_philo	*prev;

}				t_philo;

int							ft_atoi(const char *str);
t_philo						*make_philo(t_info *info);
long						get_time(long start_time);
long						get_now_time(void);
t_info						*set_philo_value(char **argv);
void						get_side_fork(t_philo *philo);
void						*routine(void *p);

#endif