/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:30:17 by sraza             #+#    #+#             */
/*   Updated: 2023/09/12 14:08:10 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

t_philo	*ft_newphilo(int num, t_info *info)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (new == NULL)
		return (NULL);
	new->id = num;
	pthread_mutex_init(&(new->my_fork), NULL);
	new->eat_count = 0;
	new->last_time_of_eat = 0;
	new->info = info;
	new->next = NULL;
	return (new);
}

t_philo	*print_philo(t_philo *philo)
{
	t_philo	*first;
	int		i;

	first = philo;
	i = 0;
	printf("start of philo->next\n");
	while (i < philo->info->num_philo)
	{
		printf("philo->id = %d\n", philo->id);
		philo = philo->next;
		i++;
	}
	printf("start of philo->prev\n");
	i = 0;
	while (i < philo->info->num_philo)
	{
		printf("philo->id = %d\n", philo->id);
		philo = philo->prev;
		i++;
	}
	return (first);
}

t_philo	*make_philo(t_info *info)
{
	int		i;
	t_philo	*first;
	t_philo	*new;
	t_philo	*tmp;

	first = ft_newphilo(1, info);
	tmp = first;
	i = 2;
	while (i < info->num_philo)
	{
		new = ft_newphilo(i, info);
		tmp->next = new;
		new->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	new = ft_newphilo(i, info);
	tmp->next = new;
	new->prev = tmp;
	tmp->next->next = first;
	first->prev = new;
	info->philo = first;
	get_side_fork(info);
	return (first);
}
