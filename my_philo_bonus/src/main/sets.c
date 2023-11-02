/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:05:53 by enveryilmaz       #+#    #+#             */
/*   Updated: 2023/11/02 02:29:46 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"
#include <stdlib.h>

void	close_all_sem(t_table *t)
{
	sem_close(t->sem_forks);
	sem_unlink("./sem_forks");
	sem_close(t->sem_print);
	sem_unlink("./sem_print");
	sem_close(t->sem_total_eat);
	sem_unlink("./sem_total_eat");
}

void	ends_of_philo(t_table *t)
{
	close_all_sem(t);
	free(t->p);
	free(t->pid);
}

int	set_table(t_table *t, char **av)
{
	t->is_die = 0;
	t->stop = 0;
	t->total_eat = 0;
	t->number_of_p = ft_atoi(av[1]);
	t->time_die = (u_int64_t)ft_atoi(av[2]);
	t->p = (t_philo *)malloc(sizeof(t_philo) * t->number_of_p);
	if (!t->p)
		return (0);
	t->pid = (pid_t *)malloc(sizeof(pid_t) * t->number_of_p);
	if (!t->pid)
		return (free(t->p), 0);
	sem_unlink("./sem_forks");
	sem_unlink("./sem_print");
	sem_unlink("./sem_total_eat");
	t->sem_forks = sem_open("./sem_forks", O_CREAT, 0666, t->number_of_p);
	if (t->sem_forks == SEM_FAILED)
		return (free(t->p), free(t->pid), 0);
	t->sem_print = sem_open("./sem_print", O_CREAT, 0666, 1);
	if (t->sem_print == SEM_FAILED)
		return (free(t->p), free(t->pid), sem_close(t->sem_forks), sem_unlink("./sem_forks"), 0);
	t->sem_total_eat = sem_open("./sem_total_eat", O_CREAT, 0666, 1);
	if (t->sem_total_eat == SEM_FAILED)
		return (free(t->p), free(t->pid), sem_close(t->sem_forks), sem_unlink("./sem_forks"), sem_close(t->sem_print), sem_unlink("./sem_print"), 0);
	return (1);
}

char	*my_join(int i)
{
	char c = (i / 100) + 48;
	char c2 = ((i / 10) % 10) + 48;
	char c3 = (i % 10) + 48;
	char *str = (char *)malloc(sizeof(char) * 6);

	str[0] = 's';
	str[1] = 'e';
	str[2] = 'm';
	str[3] = c;
	str[4] = c2;
	str[4] = c3;
	str[5] = '\0';
	return (str);
}

void	set_philo_sem(t_philo *p, int i)
{
	p->name_of_sem = my_join(i);
	p->sem_time_last_eat = sem_open(p->name_of_sem, O_CREAT, 0666, 1);
}

int	set_philos(t_table *t, char **av)
{
	int	i;

	i = 0;
	t->p = (t_philo *)malloc(sizeof(t_philo) * t->number_of_p);
	if (!t->p)
		return (ends_of_philo(t), 0);
	while (i < t->number_of_p)
	{
		t->p[i].id = i + 1;
		t->p[i].time_eat = ft_atoi(av[3]);
		t->p[i].time_sleep = ft_atoi(av[4]);
		t->p[i].num_eat = 0;
		t->p[i].must_least_eat = -1;
		if (av[5])
			t->p[i].must_least_eat = ft_atoi(av[5]);
		t->p[i].table = t;
		set_philo_sem(&t->p[i], i);
		i++;
	}
	return (1);
}