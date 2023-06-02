/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:22:29 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/02 13:54:26 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_forks(t_philo *philo)
{
	int	use;

	use = 0;
	pthread_mutex_lock(&philo->data->fork->mutex);
	if (philo->left_fork == philo->right_fork)
		use = 0;
	else if (philo->left_fork != philo->right_fork)
	{
		philo->left_fork->use = 1;
		philo->right_fork->use = 1;
	}
	else
		use = 0;
	pthread_mutex_unlock(&philo->data->fork->mutex);
	return (use);
}

int	get_time()
{
	struct timeval	current_time;
	int				real_time;

	gettimeofday(&current_time, NULL);
	real_time = (current_time.tv_sec * 1000) + current_time.tv_usec / 1000;
	return (real_time);
}

void	print_state(t_philo *philo, char *message)
{
	if (philo->died == false && philo->tt_die < philo->data->time_die)
	{
		print_state(philo, message);
		return (0);
	}
	return (1);
}

void	check_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_state(philo, FORK);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_state(philo, FORK);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	routine(t_data *data)
{
}
