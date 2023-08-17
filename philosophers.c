/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:11:24 by razasharuku       #+#    #+#             */
/*   Updated: 2023/08/17 11:36:57 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	argc_error(void)
{
	printf("USAGE: ./philo Number_of_philosophers Time_to_die Time_to_eat \
	Time_to_sleep [ Number_of_times_each_philosopher_must_eat ] \n");
	return (1);
}

t_philo *get_philo_values(char **argv)
{
	t_philo *philo;
}

int main(int argc, char **argv)
{
	struct timeval *tv;
	t_philo *philo;

	if (argc != 5 && argc != 6)
		return (argc_error());
	philo = get_philo_values(argv);
	gettimeofday(tv, NULL);
	printf("%ld %06d\n", tv->tv_sec, tv->tv_usec);
	return (0);
}