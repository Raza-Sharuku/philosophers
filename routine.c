/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:21:12 by sraza             #+#    #+#             */
/*   Updated: 2023/09/13 22:50:14 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	eating(t_philo *philo)
{
	long	ms_start;

	if (philo->info->stop_flag)
		return (1);
	pthread_mutex_lock(&philo->my_fork);
	print_condition(philo, TAKE_FORK, get_time(philo->info->start_time));
	pthread_mutex_lock(philo->side_fork);
	print_condition(philo, TAKE_FORK, get_time(philo->info->start_time));
	ms_start = get_time(philo->info->start_time);
	print_condition(philo, EATING, ms_start);
	while (1)
	{
		if (get_time(philo->info->start_time) - ms_start >= philo->info->time_to_eat)
			break ;
	}
	philo->eat_count++;
	philo->last_time_of_eat = get_time(philo->info->start_time);
	pthread_mutex_unlock(&philo->my_fork);
	pthread_mutex_unlock(philo->side_fork);
	return (0);
}

int	thinking(t_philo *philo)
{
	if (philo->info->stop_flag)
		return (1);
	print_condition(philo, THINKING, get_time(philo->info->start_time));
	return (0);
}

int	sleeping(t_philo *philo)
{
	long	ms_start;

	if (philo->info->stop_flag)
		return (1);
	ms_start = get_time(philo->info->start_time);
	print_condition(philo, SLEEPING, ms_start);
	while (1)
	{
		if (get_time(philo->info->start_time) - ms_start >= philo->info->time_to_sleep)
			break ;
	}
	return (0);
}

int	philosophers_dead(t_philo *philo)
{
	if (philo->last_time_of_eat - philo->info->start_time
		>= philo->info->time_to_die)
	{
		pthread_mutex_lock(&(philo->info->data));
		philo->info->stop_flag = 1;
		print_condition(philo, DIE, get_time(philo->info->start_time));
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
	while (1)
	{
		if (eating(philo))
			break ;
		if (philo->eat_count > philo->info->least_time_to_eat)
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
		if (philosophers_dead(philo))
			break ;
	}
	return (NULL);
}
