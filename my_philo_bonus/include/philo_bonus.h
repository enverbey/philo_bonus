/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enveryilmaz <enveryilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:55:25 by enveryilmaz       #+#    #+#             */
/*   Updated: 2023/11/02 03:26:18 by enveryilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <unistd.h>

/*
					  sem_time_last_eat
checker  : get_time - time_last_eat >= time_die
			printf("id. filo is dead");
			kill(pid, 15);	//burada tüm forkları öldür.

lie:
	if num_eat >= must_last_eat
	exit();
	// burada artık yemek yeme süresi güncellenmediği için filozof öldü diye yaazı çıkabilir, 
		-> bunun için time_last_eat = -1 yapıyoruz, bu bu argumanın kontrolünü yapma demek.
	->must_last_eat = -1 bu da yine bu armüman kontrolü yok demek.
*/

typedef struct s_philo
{
	int				id;
	int				time_eat;			//Yemek yeme süresi
	int				time_sleep;			//uyuma süresis
	int				num_eat;			//kaç defa yemek yediği
	int				must_least_eat;		//kaç defa yemek yeme sınırı olduğu
	char			*name_of_sem;
	sem_t			*sem_time_last_eat;			//time_last_eat ve time_die ulaşmak için yapılan kilit, tüm filolar için ortak olucak.
	u_int64_t		time_last_eat;		//son yemek yediği zaman  sadece bu değişkeni kullanırken sem_time_last_eat kilidi kullanılıcak.
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				stop;
	t_philo			*p;
	pid_t			*pid;						//tüm child fork'ların pid leri burada tutulacak
	sem_t			*sem_forks;						//çatallar
	sem_t			*sem_print;					//print için sem
	sem_t			*sem_total_eat;			//toplam yenen yemek sayısı için kilit
	u_int64_t		start_time;					//başlangıç zamanı
	u_int64_t		time_die;					//Açlıktan ölme süresi
	int				is_die;
	int				number_of_p;			//number of filos
	int				total_eat;
}					t_table;



//-> checker
int	checker_philo_av(int ac, char **av);
int	check_int(char **s);

//-> get time
u_int64_t	get_time(void);

//-> libft
int		ft_atoi(char *str);
int		ft_usleep(useconds_t time);

//->
void	*life(void *arg);
void	*check_die(void *arg);
void	my_printf(t_table *t, t_philo *p, char *str);

//->sets
void	close_all_sem(t_table *t);
void	ends_of_philo(t_table *t);
int		set_table(t_table *t, char **av);
int		set_philos(t_table *t, char **av);

#endif