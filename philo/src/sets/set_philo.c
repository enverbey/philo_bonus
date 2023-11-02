/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:57:19 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/30 17:46:05 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdlib.h>

void	free_destroy_falan(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_p)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->mutex_break_eat);
	pthread_mutex_destroy(&table->mutex_total_meal);
	pthread_mutex_destroy(&table->print);
	free(table->forks);
}

int	set_philos(t_table *table, t_philo **philos)
{
	int	i;

	i = 0;
	(*philos) = (t_philo *)malloc(sizeof(t_philo) * table->number_of_p);
	if (!(*philos))
		free_destroy_falan(table);
	while (i < table->number_of_p)
	{
		if (pthread_mutex_init(&(*philos)[i].mutex_w_eat, NULL))
			return (free((*philos)), free_destroy_falan(table), 0);
		(*philos)[i].left_fork = &table->forks[i];
		(*philos)[i].right_fork = &table->forks[(i + 1) % table->number_of_p];
		(*philos)[i].number = i + 1;
		(*philos)[i].time_without_eat = 0;
		(*philos)[i].table = table;
		i++;
	}
	return (1);
}
