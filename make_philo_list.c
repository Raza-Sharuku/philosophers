/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_philo_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:30:17 by sraza             #+#    #+#             */
/*   Updated: 2023/08/27 16:18:34 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

t_philo *ft_newphilo(int num)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (new == NULL)
		return (NULL);
	new->id = num;
	new->next = NULL;
	return (new);
}

t_philo	*make_philo(t_info *info)
{
	int	i;
	t_philo *first;
	t_philo *new;
	t_philo *tmp;

	first = ft_newphilo(1);
	tmp = first;
	i = 2;
	while (i < info->num_philo)
	{
		new = ft_newphilo(i);
		tmp->next = new;
		new->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	new = ft_newphilo(i);
	tmp->next = new;
	new->prev = tmp;
	tmp->next->next = first;
	first->prev = new;
	return (first);
}
