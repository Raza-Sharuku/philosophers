/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:59:18 by sraza             #+#    #+#             */
/*   Updated: 2023/09/12 14:04:06 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

long	get_time(long start_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start_time);
}

long	get_now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

t_info	*set_philo_value(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info) * 1);
	if (info == NULL)
		return (NULL);
	info->num_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->least_time_to_eat = ft_atoi(argv[5]);
	else
		info->least_time_to_eat = INT_MAX;
	info->start_time = get_now_time();
	info->stop_flag = 0;
	return (info);
}

void	get_side_fork(t_info *info)
{
	t_philo	*tmp;
	int		i;

	i = 0;
	tmp = info->philo;
	while (i < info->num_philo)
	{
		tmp->side_fork = &tmp->next->my_fork;
		tmp = tmp->next;
		i++;
	}
}
