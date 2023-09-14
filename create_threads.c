/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:43:02 by sraza             #+#    #+#             */
/*   Updated: 2023/09/14 21:41:49 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	can_mutex(t_philo *philo)
{
	if (philo->info->stop_flag > 0)
		return (1);
	if (philosophers_dead(philo))
		return (1);
	return (0);
}

void	*monitering_routine(void *p)
{
	t_philo	*philo;
	int		eat_count;

	eat_count = 0;
	philo = (t_philo *)p;
	while (1)
	{
		if (can_mutex(philo))
			break ;
		if (philo->id == 1)
			eat_count = 0;
		if (philo->eat_count >= philo->info->least_time_to_eat)
			eat_count++;
		if (eat_count >= philo->info->num_philo)
		{
			philo->info->stop_flag = 1;
			break ;
		}
		philo = philo->next;
	}
	return (NULL);
}

t_philo	*creating_threads(t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = philo;
	while (i < philo->info->num_philo)
	{
		pthread_create(&tmp->thread, NULL, &routine, tmp);
		tmp = tmp->next;
		i++;
	}
	tmp = philo;
	pthread_create(&(tmp->info->moniter), NULL, &monitering_routine, tmp);
	return (philo);
}
