/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:04:10 by enveryilmaz       #+#    #+#             */
/*   Updated: 2023/11/02 03:24:59 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>

void	my_printf(t_table *t, t_philo *p, char *str)
{
	sem_wait(t->sem_print);
	if (!t->is_die)
		printf("%llu %d. %s", get_time() - t->start_time, p->id, str);
	sem_post(t->sem_print);
}
/*
	5. argumen ile ilgili kontrol burada yapılmakta açlık kontrolü check_die tarafından yapılacaktır.
*/

void	*life(void *arg)
{
	t_table	*t;
	t_philo *p;

	p = (t_philo *)arg;
	t = (t_table *)p->table;
	if (p->id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		if (p->must_least_eat != -1 && p->num_eat >= p->must_least_eat)
			return (NULL);
		while (1)
		{
			sem_wait(t->sem_print);
			if (t->is_die == 1)
			{
				sem_post(t->sem_print);
				return (NULL);
			}
			sem_post(t->sem_print);
			sem_wait(t->sem_total_eat);
			if (t->total_eat / t->number_of_p < p->num_eat)
			{
				sem_post(t->sem_total_eat);
				ft_usleep(5);
			}
			else
			{
				sem_post(t->sem_total_eat);
				break ;
			}
		}
		sem_wait(t->sem_forks);
		my_printf(t, p, "\033[0;36mphilo has taken a fork\033[0;0m\n");
		sem_wait(t->sem_forks);
		my_printf(t, p, "\033[0;36mphilo has taken a fork\033[0;0m\n");
		my_printf(t, p, "\033[0;33mphilo is eating\033[0;0m\n");
		sem_wait(p->sem_time_last_eat);
		p->time_last_eat = get_time();
		sem_post(p->sem_time_last_eat);
		sem_wait(t->sem_total_eat);
		t->total_eat++;
		sem_post(t->sem_total_eat);
		ft_usleep(p->time_eat);
		p->num_eat++;
		sem_post(t->sem_forks);
		sem_post(t->sem_forks);
		my_printf(t, p, "\033[0;32mphilo is sleeping\033[0;0m\n");
		ft_usleep(p->time_sleep);
		my_printf(t, p, "\033[0;35mphilo is thinking\033[0;0m\n");
	}
}