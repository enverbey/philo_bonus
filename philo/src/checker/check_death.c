/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:09:39 by envyilma          #+#    #+#             */
/*   Updated: 2023/09/23 18:25:34 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdio.h>

void	unluck_everything(t_table *table)
{
	int	i;

	i = -1;
	while (i++, i < table->number_of_p)
		pthread_mutex_unlock(&table->forks[i]);
}

int	is_there_dead(t_philo *philo, t_table *table, int i)
{
	if (philo[i].time_without_eat >= table->death_time)
	{
		pthread_mutex_lock(&philo->table->print);
		printf("%llu %d. %s",
			get_time() - philo->table->start, philo->number, "is dead");
		pthread_mutex_lock(&table->mutex_break_eat);
		table->break_eat = 1;
		unluck_everything(table);
		pthread_mutex_unlock(&table->mutex_break_eat);
		pthread_mutex_unlock(&philo[i].mutex_w_eat);
		pthread_mutex_unlock(&philo->table->print);
		return (0);
	}
	return (1);
}

int	loop_control(t_philo *philo, t_table *table)
{
	int	i;

	i = -1;
	while (i++, i < table->number_of_p)
	{
		pthread_mutex_lock(&philo[i].mutex_w_eat);
		philo[i].time_without_eat++;
		if (is_there_dead(philo, table, i) == 0)
			return (0);
		pthread_mutex_unlock(&philo[i].mutex_w_eat);
		pthread_mutex_lock(&table->mutex_total_meal);
		if (table->must_least_eat != -1 && table->total_meal
			/ table->number_of_p >= table->must_least_eat)
		{
			pthread_mutex_lock(&table->mutex_break_eat);
			table->break_eat = 1;
			unluck_everything(table);
			pthread_mutex_unlock(&table->mutex_break_eat);
			pthread_mutex_unlock(&table->mutex_total_meal);
			return (0);
		}
		pthread_mutex_unlock(&table->mutex_total_meal);
	}
	return (1);
}

void	*check_death(void *philos)
{
	t_philo	*philo;
	t_table	*table;

	philo = *(t_philo **)(philos);
	table = philo->table;
	pthread_mutex_lock(&table->print);
	table->start = get_time();
	pthread_mutex_unlock(&table->print);
	while (1)
	{
		if (loop_control(philo, table) == 0)
			return (NULL);
		ft_usleep(1);
	}
}
