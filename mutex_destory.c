/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:03:52 by razasharuku       #+#    #+#             */
/*   Updated: 2023/09/14 22:09:45 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	destroy_mutex_forks(t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	tmp = philo;
	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_destroy(&tmp->my_fork);
		tmp = tmp->next;
		i++;
	}
	pthread_mutex_destroy(&philo->info->data);
	pthread_mutex_destroy(&philo->info->print);
	return (0);
}
