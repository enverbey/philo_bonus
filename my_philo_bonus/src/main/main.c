/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:24:43 by envyilma          #+#    #+#             */
/*   Updated: 2023/11/02 03:25:06 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>

void	start_life(t_table *t)
{
	int	i;
	pthread_t	*id;
	pthread_t	check;
	id = (pthread_t *)malloc(sizeof(pthread_t) * t->number_of_p);

	i = 0;
	t->start_time = get_time();
	while (i < t->number_of_p)
	{
		t->p[i].time_last_eat = t->start_time;
		pthread_create(&id[i], NULL, life, (void *)&t->p[i]);
		i++;
	}
	pthread_create(&check, NULL, check_die, (void *)t);
	i = 0;
	while (i < t->number_of_p)
	{
		pthread_join(id[i], NULL);
		i++;
	}
	pthread_join(check, NULL);
	free(id);
	ends_of_philo(t);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (!checker_philo_av(ac, av))
		return (printf("Error\n"), 1);
	if (!set_table(&table, av))
		return (printf("Error\n"), 1); 
	if (!set_philos(&table, av))
		return (printf("Error\n"), 1);
	start_life(&table);	//1 leaks var ama bulamıyorum
	return (0);
}
