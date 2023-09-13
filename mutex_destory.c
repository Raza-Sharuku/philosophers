/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:03:52 by razasharuku       #+#    #+#             */
/*   Updated: 2023/09/13 11:27:00 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

static int	destroy_mutex_forks(t_philo *philo)
{
	int	i;
	t_philo	*tmp;

	tmp = philo;
	i = 0;
	while (i < philo->info->num_philo)
	{
		pthread_mutex_destroy(&tmp->my_fork);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

