/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:40:34 by envyilma          #+#    #+#             */
/*   Updated: 2023/09/23 13:08:41 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	eat_meal_x(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(philo->left_fork);
	ft_message("philo has taken a fork\n", philo);
	pthread_mutex_lock(philo->right_fork);
	ft_message("philo has taken a fork\n", philo);
	pthread_mutex_lock(&philo->mutex_w_eat);
	philo->time_without_eat = 0;
	pthread_mutex_unlock(&philo->mutex_w_eat);
	pthread_mutex_lock(&table->mutex_total_meal);
	table->total_meal++;
	pthread_mutex_unlock(&table->mutex_total_meal);
	ft_message("philo is eating\n", philo);
	ft_usleep(table->time_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	ft_message("philo is sleeping\n", philo);
	ft_usleep(table->time_sleep);
	ft_message("philo is thinking\n", philo);
}

void	*eat(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)data;
	table = philo->table;
	if (philo->number % 2 == 1)
		ft_usleep(5);
	while (1)
	{
		pthread_mutex_lock(&table->mutex_break_eat);
		if (table->break_eat == 1)
		{
			pthread_mutex_unlock(&table->mutex_break_eat);
			break ;
		}
		pthread_mutex_unlock(&table->mutex_break_eat);
		eat_meal_x(philo, table);
	}
	return (NULL);
}
