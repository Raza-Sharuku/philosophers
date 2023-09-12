/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:43:02 by sraza             #+#    #+#             */
/*   Updated: 2023/09/12 19:47:58 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

// void	*monitering_routine(void *p)
// {
// 	t_info	*moniter;

// 	moniter = (t_info *)p;
// 	while (moniter->stop_flag == 0)
// 	{
// 		if (philosophers_dead(moniter->philo))
			
			
// 	}
// 	return;
// }

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
	// pthread_create(&tmp->info->moniter, NULL, &monitering_routine, &tmp->info);
	return (philo);
}
