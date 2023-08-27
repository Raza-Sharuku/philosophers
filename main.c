/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:52 by sraza             #+#    #+#             */
/*   Updated: 2023/08/27 15:37:11 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	argc_error(void)
{
	printf("USAGE: ./philo Number_of_philosophers Time_to_die Time_to_eat \
	Time_to_sleep [ Number_of_times_each_philosopher_must_eat ] \n");
	return (1);
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
	return (info);
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;
	pthread_t *p;

	if (argc != 5 && argc != 6)
		return (argc_error());
	info = set_philo_value(argv);
	if (info == NULL)
		return (1);
	philo = make_philo(info);
	
	return (0);
}

// TIMEVAL_TO_TIMESPEC(tv, ts)
// {
// 	(ts)->tv_sec = (tv)->tv_sec;
// 	(ts)->tv_nsec = (tv)->tv_usec * 1000; \
// }
