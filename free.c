/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:27:21 by sraza             #+#    #+#             */
/*   Updated: 2023/09/05 17:16:22 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	*free_circle_list(t_info *info, t_philo *philo)
{
	t_philo *first;
	t_philo *tmp;

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
	return NULL;
}