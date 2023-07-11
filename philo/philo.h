/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:54 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/07/11 15:30:30 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>

# define THINKING "is thinking"
# define EATING "is eating"
# define DIED "died"
# define SLEEP "is sleeping"
# define FORK "has taken a fork"

typedef long long	t_time;

typedef struct s_fork
{
	bool			use;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data
{
	struct s_philo	*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
	pthread_mutex_t	check_fork;
	t_fork			*fork;
	int				nb_philo;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	int				nb_meal;
	bool			died;
	bool			meal;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				nb;
	t_time			tt_die;
	t_fork			*left_fork;
	t_fork			*right_fork;
	bool			died;
	int				nb_meal;
	t_data			*data;
	int				temp;
}	t_philo;

long		ft_liatoi(const char *str);
int			is_int(char *av);
int			ft_strlen(char *str);
void		ft_bzero(void *str, size_t n);
int			args_checker(int ac, char **av, t_data *data);
int			check_forks(t_philo *philo);
void		*life(void *ptr);
t_time		get_time(void);
int			ft_atoi(const char *str);
int			mutex_init(t_data *data);
void		init_data(char **av, t_data *data);
int			destroy_mutex(t_data *data);
int			init_philo(t_data *data);
int			create_philo(t_data *data);
int			stop_philo(t_data *data);
void		smart_usleep(t_time time, t_philo *philo);
void		check_if_dead(t_philo *philo);
int			ft_isdigit(int c);
int			check_dead(t_philo *philo);

#endif