/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:07:13 by envyilma          #+#    #+#             */
/*   Updated: 2023/09/23 18:21:54 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdio.h>

void	ft_message(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->mutex_break_eat);
	if (philo->table->break_eat != 1)
		printf("%llu %d. %s",
			get_time() - philo->table->start, philo->number, str);
	pthread_mutex_unlock(&philo->table->mutex_break_eat);
	pthread_mutex_unlock(&philo->table->print);
}
