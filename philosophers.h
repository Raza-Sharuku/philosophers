/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:12:01 by razasharuku       #+#    #+#             */
/*   Updated: 2023/09/12 19:45:17 by sraza            ###   ########.fr       */
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

typedef struct s_timeval
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}			t_timeval;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				least_time_to_eat;
	time_t			start_time;
	atomic_int		stop_flag;
	pthread_t		moniter;
	struct s_philo	*philo;
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

typedef enum e_philo_condition
{
	TAKE_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIE,
}	t_philo_condition;

int							ft_atoi(const char *str);
t_philo						*make_philo(t_info *info);
long						get_time(long start_time);
long						get_now_time(void);
t_info						*set_philo_value(char **argv);
void						get_side_fork(t_info *info);
void						*routine(void *p);
void						*free_circle_list(t_info *info, t_philo *philo);
t_philo						*creating_threads(t_philo *philo);
void						print_condition(t_philo *philo,
								t_philo_condition cond);
int							philosophers_dead(t_philo *philo);

#endif