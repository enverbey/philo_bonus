/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:23:28 by envyilma          #+#    #+#             */
/*   Updated: 2023/10/31 12:05:46 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H 19092023L

# include <pthread.h>
# include <unistd.h>

typedef struct s_table
{
	pthread_t		check_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_break_eat;
	pthread_mutex_t	mutex_total_meal;
	u_int64_t		start;
	int				number_of_p;
	int				time_eat;
	int				time_sleep;
	int				death_time;
	int				break_eat;
	int				total_meal;
	int				must_least_eat;
}	t_table;

typedef struct s_philo
{
	pthread_t		philo_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	mutex_w_eat;
	int				number;
	int				time_without_eat;
	t_table			*table;
}	t_philo;

// -> checker
void		*check_death(void *philos);
int			checker_philo_av(int ac, char **av);

// -> free
void		free_everything(t_philo *philos);

// -> output
void		ft_message(char *str, t_philo *philo);

// -> get time
u_int64_t	get_time(void);
int			ft_usleep(useconds_t time);

// -> libft 
int			ft_atoi(char *str);

// -> main
void		*eat(void *data);

// -> sets
int			set_philos(t_table *table, t_philo **philos);
int			set_table(t_table *table, char **av);

#endif
