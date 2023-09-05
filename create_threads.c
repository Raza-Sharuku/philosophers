/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:43:02 by sraza             #+#    #+#             */
/*   Updated: 2023/09/05 18:10:33 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

// void	monitering_routine(void *p)
// {
// 	p = NULL;

// 	return;
// }

t_info	*creating_threads(t_info *info)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = info->philo;
	printf("%d\n", info->num_philo);
	while (i < info->num_philo)
	{
		pthread_create(&tmp->thread, NULL, &routine, tmp);
		tmp = tmp->next;
		i++;
	}
	// pthread_create(&info->moniter, NULL, &monitering_routine, info);
	return (info);
}
