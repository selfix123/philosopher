/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:54 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/31 15:05:54 by zbeaumon         ###   ########.fr       */
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

typedef	struct s_fork
{
	pthread_mutex_t	*fork;
	bool			use;
}	t_fork;

typedef struct s_data
{
	int		time_dead;
	int		time_eat;
	int		time_sleep;
	int		nb_meal;
	bool	meal;
	int		nb_philo;
}	t_data;

typedef struct s_philo
{
	t_fork	*fork;
	pthread_mutex_t *die;
	pthread_mutex_t *philo;
	pthread_mutex_t *print;
	t_data		time_dead;
	t_data		time_eat;
	t_data		time_sleep;
	t_data		nb_philo;
	t_data	*data;
	t_fork	use;
}	t_philo;

long	ft_liatoi(const char *str);
int		is_int(int ac, char **av);
int		ft_strlen(char *str);
void	ft_bzero(void *str, size_t n);
int		args_checker(int ac, char **av, t_data *data);

#endif