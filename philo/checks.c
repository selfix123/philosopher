/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:22:29 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/12 13:34:47 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->died == false && philo->tt_die < philo->data->time_die)
		printf("%d %d %s\n", get_time(), philo->data->nb_philo, message);
	pthread_mutex_unlock(&philo->data->print);
}

int	check_if_dead(t_data *data)
{
	pthread_mutex_lock(&data->die);
	if (data->time_die <= get_time())
	{
		data->philo->died = true;
		data->died = true;
		print_state(data->philo, DIED);
	}
	pthread_mutex_unlock(&data->die);
	return (0);
}

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

void	check_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_state(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_state(philo, FORK);
	print_state(philo, EATING);
	philo->tt_die = get_time() + philo->data->time_die;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	philo->left_fork->use = false;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	philo->right_fork->use = false;
}

void	*life(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->nb & 1)
		usleep(150);
	while (philo->data->died == false)
	{
		print_state(philo, THINKING);
		if (!philo->died)
			check_eat(philo);
		if (philo->data->meal == true)
			philo->data->nb_meal--;
		if (philo->data->meal == true && philo->data->nb_meal == 0)
			return (NULL);
		if (!philo->died)
			print_state(philo, SLEEP);
	}
	return (NULL);
}
