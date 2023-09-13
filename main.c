/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:52 by sraza             #+#    #+#             */
/*   Updated: 2023/09/13 21:57:19 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	argc_error(int argc, char **argv)
{
	int d;

	d = 0;
	if (argc != 5 && argc != 6)
	{
		d = printf("USAGE: ./philo Number_of_philosophers Time_to_die Time_to_eat \
		Time_to_sleep [ Number_of_times_each_philosopher_must_eat ] \n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
	|| ft_atoi(argv[4]) < 0)
		d = printf("MINUS NUMBER; WRITE POSITIVE NUMBER WITHOUT +\n");
	if (argc == 6  && (ft_atoi(argv[5]) < 0))
		d = printf("MINUS NUMBER; WRITE POSITIVE NUMBER WITHOUT +\n");
	if (ft_isalpha(argv[1]) || ft_isalpha(argv[2]) || ft_isalpha(argv[3])
	|| ft_isalpha(argv[4]))
		d = printf("ALPHABETS;    WRITE POSITIVE NUMBER WITHOUT +\n");
	if (argc == 6  && (ft_isalpha(argv[5])))
		d = printf("ALPHABETS;    WRITE POSITIVE NUMBER WITHOUT +\n");
	if (d != 0)
		return (1);
	return (0);
}

// int	alone_philo(t_philo *philo)
// {
// 	long	ms;

// 	ms = get_now_time();
// 	if (pthread_create(&philo->thread, NULL, &monitering_routine, philo))
// 		return (1);
// 	if (pthread_create(&philo->thread, NULL, &routine, philo))
// 		return (1);
	
// 	pthread_detach(philo->thread);
// 	while (philo->info->stop_flag == 0)
// 		while  (get_now_time() - ms < 0)
// 			break ;
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_info		*info;
	t_philo		*philo;
	int			i;

	if (argc_error(argc, argv))
		return (1);
	info = set_philo_value(argv);
	if (info == NULL)
		return (1);
	philo = make_philo(info);
	// if (info->num_philo == 1)
	// 	return (alone_philo(philo));
	philo = creating_threads(philo);
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
			return (-1);
		philo = philo->next;
		i++;
	}
	pthread_join(info->moniter, NULL);
	free_circle_list(info, philo);
	return (0);
}
