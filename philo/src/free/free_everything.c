/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:16:48 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/30 17:45:17 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdlib.h>

void	free_everything(t_philo *philos)
{
	int		i;
	t_table	*table;

	i = -1;
	table = philos->table;
	while (i++, i < table->number_of_p)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&philos->mutex_w_eat);
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->mutex_break_eat);
	pthread_mutex_destroy(&table->mutex_total_meal);
	free(table->forks);
	free(philos);
}
