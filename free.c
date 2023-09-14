/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:21 by sraza             #+#    #+#             */
/*   Updated: 2023/09/14 22:10:13 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*free_circle_list(t_info *info, t_philo *philo)
{
	t_philo	*tmp;
	t_philo	*free_n;
	int		i;

	i = 0;
	tmp = philo;
	while (i < philo->info->num_philo)
	{
		free_n = tmp;
		tmp = tmp->next;
		free(free_n);
		i++;
	}
	(void)(info);
	return (NULL);
}
