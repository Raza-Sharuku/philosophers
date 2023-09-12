/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:21:12 by sraza             #+#    #+#             */
/*   Updated: 2023/09/12 14:07:25 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->my_fork);
	print_condition(philo, TAKE_FORK);
	pthread_mutex_lock(philo->side_fork);
	print_condition(philo, TAKE_FORK);
	print_condition(philo, EATING);
	usleep(philo->info->time_to_eat);
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
	print_condition(philo, SLEEPING);
	usleep(philo->info->time_to_sleep);
	return (1);
}

int	philosophers_dead(t_philo *philo)
{
	if (philo->info->start_time - philo->last_time_of_eat
		>= philo->info->time_to_die)
	{
		printf("%ld %i is dead\n", get_time(philo->info->start_time), philo->id);
		philo->info->stop_flag = 1;
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
		eating(philo);
		sleeping(philo);
		thinking(philo);
		if (philo->eat_count > philo->info->least_time_to_eat)
			break ;
		philosophers_dead(philo);
	}
	return (NULL);
}
