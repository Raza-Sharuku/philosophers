/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:21:52 by sraza             #+#    #+#             */
/*   Updated: 2023/09/14 22:08:42 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	argc_error(int argc, char **argv)
{
	int	d;

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
	if (argc == 6 && (ft_atoi(argv[5]) < 0))
		d = printf("MINUS NUMBER; WRITE POSITIVE NUMBER WITHOUT +\n");
	if (ft_isalpha(argv[1]) || ft_isalpha(argv[2]) || ft_isalpha(argv[3])
		|| ft_isalpha(argv[4]))
		d = printf("ALPHABETS;    WRITE POSITIVE NUMBER WITHOUT +\n");
	if (argc == 6 && (ft_isalpha(argv[5])))
		d = printf("ALPHABETS;    WRITE POSITIVE NUMBER WITHOUT +\n");
	if (d != 0)
		return (1);
	return (0);
}

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
	destroy_mutex_forks(philo);
	free_circle_list(info, philo);
	return (0);
}
