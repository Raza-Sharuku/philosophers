/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:52 by sraza             #+#    #+#             */
/*   Updated: 2023/09/06 11:28:55 by razasharuku      ###   ########.fr       */
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

	if (argc != 5 && argc != 6)
		return (argc_error());
	info = set_philo_value(argv);
	if (info == NULL)
		return (1);
	philo = make_philo(info);
	philo = creating_threads(philo);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
			return (-1);
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
