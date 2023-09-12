/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:21 by sraza             #+#    #+#             */
/*   Updated: 2023/09/12 14:05:48 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*free_circle_list(t_info *info, t_philo *philo)
{
	t_philo	*first;
	t_philo	*tmp;

	first = philo;
	philo = philo->prev;
	philo->next = NULL;
	while (first != NULL)
	{
		tmp = first;
		first = first->next;
		free(tmp);
	}
	free(first);
	(void)(info);
	return (NULL);
}
