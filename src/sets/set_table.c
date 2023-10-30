/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:54:52 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/30 17:49:30 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdlib.h>

static int	set_table_cont(t_table *table, int i)
{
	if (!table->forks)
	{
		pthread_mutex_destroy(&table->mutex_break_eat);
		pthread_mutex_destroy(&table->mutex_total_meal);
		pthread_mutex_destroy(&table->print);
		return (0);
	}
	while (i++, i < table->number_of_p)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			while (i--, i >= 0)
				pthread_mutex_destroy(&table->forks[i]);
			pthread_mutex_destroy(&table->mutex_break_eat);
			pthread_mutex_destroy(&table->mutex_total_meal);
			pthread_mutex_destroy(&table->print);
			free(table->forks);
			return (0);
		}
	}
	return (1);
}

int	set_table(t_table *table, char **av)
{
	int	i;

	i = -1;
	table->number_of_p = ft_atoi(av[1]);
	table->death_time = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	if (pthread_mutex_init(&table->mutex_break_eat, NULL))
		return (0);
	if (pthread_mutex_init(&table->mutex_total_meal, NULL))
		return (pthread_mutex_destroy(&table->mutex_break_eat), 0);
	if (av[5])
		table->must_least_eat = ft_atoi(av[5]);
	else
		table->must_least_eat = -1;
	table->break_eat = 0;
	table->total_meal = 0;
	if (pthread_mutex_init(&table->print, NULL))
		return (pthread_mutex_destroy(&table->mutex_break_eat), \
			pthread_mutex_destroy(&table->mutex_total_meal), 0);
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->number_of_p);
	return (set_table_cont(table, i));
}
