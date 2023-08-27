/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:52 by sraza             #+#    #+#             */
/*   Updated: 2023/08/27 16:24:11 by sraza            ###   ########.fr       */
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
	t_info		*info;
	t_philo		*philo;
	pthread_t	*p;
	int			i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (argc_error());
	info = set_philo_value(argv);
	if (info == NULL)
		return (1);
	philo = make_philo(info);
	p = (pthread_t)malloc(sizoeof(pthread_t) * info->num_philo);
	while (i < info->num_philo)
	{
		if (pthread_create(p[i], NULL, &philo, philo) != 0)
			return (-1);
		philo = philo->next;
		i++;
	}
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(p[i], NULL) != 0)
			return (-1);
		philo = philo->next;
		i++;
	}	
	return (0);
}

// TIMEVAL_TO_TIMESPEC(tv, ts)
// {
// 	(ts)->tv_sec = (tv)->tv_sec;
// 	(ts)->tv_nsec = (tv)->tv_usec * 1000; \
// }
