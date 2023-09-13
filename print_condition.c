/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:40:11 by razasharuku       #+#    #+#             */
/*   Updated: 2023/09/13 22:48:50 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	print_condition(t_philo *philo, t_philo_condition cond, long ms)
{
	pthread_mutex_lock(&(philo->info->print));
	if (philo->info->stop_flag && cond != DIE)
	{
		pthread_mutex_unlock(&philo->my_fork);
		return ;
	}
	if (cond == TAKE_FORK)
		printf("%ld %d has taken a fork\n", ms, philo->id);
	else if (cond == EATING)
		printf("%ld %d is eating\n", ms, philo->id);
	else if (cond == SLEEPING)
		printf("%ld %d is sleeping\n", ms, philo->id);
	else if (cond == THINKING)
		printf("%ld %d is thinking\n", ms, philo->id);
	else if (cond == DIE)
		printf("%ld %d is died\n", ms, philo->id);
	pthread_mutex_unlock(&(philo->info->print));
	return ;
}
