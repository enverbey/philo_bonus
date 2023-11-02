/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:32:23 by enveryilmaz       #+#    #+#             */
/*   Updated: 2023/11/02 03:26:37 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"
#include <stdio.h>

void	*check_die(void *arg)
{
	t_table	*t;
	int		i;
	//1-toplam yenen yemek sayısı / filozof sayısı == zorunlu yemek sayısı ise, is_die = 1 yap ve bitir.
	//2- get_time - last_eat >= die_time , o zaman, ölüm mesajjı yazdır,  is_die = 1 yap ve bitir.
	t = (t_table *)arg;
	while (1)
	{
		i = 0;
		if (t->p[0].must_least_eat != -1 && t->total_eat / t->number_of_p >= t->p[0].must_least_eat)
			return (NULL);
		while (i < t->number_of_p)
		{
			sem_wait(t->p[i].sem_time_last_eat);
			if (get_time() - t->p[i].time_last_eat >= t->time_die)
			{
				my_printf(t, &t->p[i], "\033[0;31mphilo is dead\033[0;0m\n");
				sem_post(t->p[i].sem_time_last_eat);
				t->is_die = 1;
				return (NULL);
			}
			sem_post(t->p[i].sem_time_last_eat);
			i++;
		}
		ft_usleep(10);
	}
	return (NULL);
}