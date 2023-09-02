/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:52 by sraza             #+#    #+#             */
/*   Updated: 2023/09/02 20:20:46 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	argc_error(void)
{
	printf("USAGE: ./philo Number_of_philosophers Time_to_die Time_to_eat \
	Time_to_sleep [ Number_of_times_each_philosopher_must_eat ] \n");
	return (1);
}

void	creating_threads(t_info *info)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = info->philo;
	while (i < info->num_philo)
	{
		pthread_create(&tmp->thread, NULL, &routine, tmp);
		tmp = tmp->next;
		i++;
	}
	pthread_create(&info->moniter, NULL, &monitering_routine, info);
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
	info->philo = make_philo(info);
	creating_threads(info);
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
