/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:21:12 by sraza             #+#    #+#             */
/*   Updated: 2023/09/02 20:46:35 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->my_fork);
	printf("%ld %i has taken a fork\n", get_time(philo->info->start_time), philo->id);
	pthread_mutex_lock(&philo->side_fork);
	printf("%ld %i has taken a fork\n", get_time(philo->info->start_time), philo->id);
	usleep(1);
	pthread_mutex_unlock(&philo->my_fork);
	return (0);
}

int	sleeping(t_philo *philo)
{
	usleep(philo->info->time_to_sleep);
	return (1);
}

int	thinking(t_philo *philo)
{

}

void	*routine(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	while (1)
	{
		
	}
}