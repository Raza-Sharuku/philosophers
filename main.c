/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:52 by sraza             #+#    #+#             */
/*   Updated: 2023/09/05 18:13:22 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	argc_error(void)
{
	printf("USAGE: ./philo Number_of_philosophers Time_to_die Time_to_eat \
	Time_to_sleep [ Number_of_times_each_philosopher_must_eat ] \n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philo;
	int			i;

	i = 0;
	philo = NULL;
	if (argc != 5 && argc != 6)
		return (argc_error());
	info = set_philo_value(argv);
	if (info == NULL)
		return (1);
	info->philo = make_philo(info);
	info = creating_threads(info);
	i = 0;
	printf("philo.num = %i\n", philo->id);
	while (i < info->num_philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
			return (-1);
		printf("tmp->id %i, i = %i\n", philo->id, i);
		philo = philo->next;
		i++;
	}
	// free_circle_list(info, philo);
	return (0);
}

// TIMEVAL_TO_TIMESPEC(tv, ts)
// {
// 	(ts)->tv_sec = (tv)->tv_sec;
// 	(ts)->tv_nsec = (tv)->tv_usec * 1000; \
// }
