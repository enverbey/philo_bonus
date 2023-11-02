/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:24:43 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/30 17:41:15 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdio.h>

void	start_philo(t_table *table, t_philo **philolar)
{
	t_philo	*philos;
	int		i;

	philos = (*philolar);
	i = -1;
	pthread_create(&table->check_dead, NULL, check_death, (void *)(&philos));
	while (i++, i < table->number_of_p)
		pthread_create(&philos[i].philo_id, NULL, eat, (void *)&philos[i]);
	i = -1;
	pthread_join(table->check_dead, NULL);
	while (i++, i < table->number_of_p)
		pthread_join(philos[i].philo_id, NULL);
}

int	main(int ac, char **av)
{
	t_philo		*philos;
	t_table		table;

	philos = NULL;
	if (!checker_philo_av(ac, av))
		return (printf("Error\n"), 0);
	if (!set_table(&table, av))
		return (0);
	if (!set_philos(&table, &philos))
		return (0);
	start_philo(&table, &philos);
	free_everything(philos);
}
