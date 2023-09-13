/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:21:12 by sraza             #+#    #+#             */
/*   Updated: 2023/09/13 21:00:46 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	eating(t_philo *philo)
{
	long	ms_start;

	pthread_mutex_lock(&philo->my_fork);
	print_condition(philo, TAKE_FORK);
	pthread_mutex_lock(philo->side_fork);
	print_condition(philo, TAKE_FORK);
	print_condition(philo, EATING);
	ms_start = get_now_time();
	while (1)
	{
		if (get_now_time() - ms_start > philo->info->time_to_eat)
			break ;
	}
	philo->eat_count++;
	philo->last_time_of_eat = get_now_time();
	pthread_mutex_unlock(&philo->my_fork);
	pthread_mutex_unlock(philo->side_fork);
	return (0);
}

int	thinking(t_philo *philo)
{
	print_condition(philo, THINKING);
	return (0);
}

int	sleeping(t_philo *philo)
{
	long	ms_start;

	print_condition(philo, SLEEPING);
	ms_start = get_now_time();
	while (1)
	{
		if (get_now_time() - ms_start > philo->info->time_to_sleep)
			break ;
	}
	return (1);
}

int	philosophers_dead(t_philo *philo)
{
	if (philo->last_time_of_eat - philo->info->start_time
		>= philo->info->time_to_die)
	{
		pthread_mutex_lock(&(philo->info->data));
		philo->info->stop_flag = 1;
		print_condition(philo, DIE);
		pthread_mutex_unlock(&(philo->info->data));
		return (1);
	}
	return (0);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		sleeping(philo);
	while (philo->info->stop_flag == 0)
	{
		pthread_mutex_lock(&(philo->info->data));
		eating(philo);
		if (philo->eat_count > philo->info->least_time_to_eat)
			break ;
		// if (philo->info->stop_flag == 1)
		// 	break ;
		sleeping(philo);
		thinking(philo);
		pthread_mutex_unlock(&(philo->info->data));
		// philosophers_dead(philo);
	}
	return (NULL);
}
