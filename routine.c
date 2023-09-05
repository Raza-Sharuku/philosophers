/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:21:12 by sraza             #+#    #+#             */
/*   Updated: 2023/09/05 18:04:02 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->my_fork);
	printf("%ld %i has taken a fork\n", get_time(philo->info->start_time), philo->id);
	pthread_mutex_lock(philo->side_fork);
	printf("%ld %i has taken a fork\n", get_time(philo->info->start_time), philo->id);
	printf("%ld %i is eating\n", get_time(philo->info->start_time), philo->id);
	usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&philo->my_fork);
	pthread_mutex_unlock(philo->side_fork);
	return (0);
}

int	sleeping(t_philo *philo)
{
	printf("%ld %i is sleeping\n", get_time(philo->info->start_time), philo->id);
	usleep(philo->info->time_to_sleep);
	return (1);
}

int	philosophers_dead(t_philo *philo)
{
	if (philo->info->start_time - philo->last_time_of_eat >= philo->info->time_to_die)
	{
		printf("%ld %i is dead\n", get_time(philo->info->start_time), philo->id);
		philo->info->stop_flag = 1;
		return (1);
	}
	return (0);
}

void	*routine(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	while (philo->info->stop_flag == 0)
	{
		if (philo->id % 2 == 0)
		{
			eating(philo);
			sleeping(philo);
		}
		if (philo->id % 2 == 1)
		{
			sleeping(philo);
			eating(philo);
		}
		philosophers_dead(philo);
	}
	return (NULL);
}