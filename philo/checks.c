/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:22:29 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/07/11 15:30:48 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print);
	if (!check_dead(philo) || (check_dead(philo) && philo->died))
		printf("%lld %d %s\n", get_time(), philo->nb, message);
	pthread_mutex_unlock(&philo->data->print);
}

void	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die);
	if (!philo->data->died)
	{
		philo->died = true;
		philo->data->died = true;
		pthread_mutex_unlock(&philo->data->die);
		print_state(philo, DIED);
		return ;
	}
	pthread_mutex_unlock(&philo->data->die);
}

int	check_forks(t_philo *philo)
{
	int	use;

	pthread_mutex_lock(&philo->data->check_fork);
	if (philo->left_fork == philo->right_fork)
		use = 0;
	else if (!philo->left_fork->use && !philo->right_fork->use)
	{
		philo->left_fork->use = true;
		philo->right_fork->use = true;
		use = 1;
	}
	else
		use = 0;
	pthread_mutex_unlock(&philo->data->check_fork);
	return (use);
}

void	check_eat(t_philo *philo)
{
	usleep(500);
	while (!check_forks(philo) || philo->tt_die <= get_time())
	{
		if (philo->tt_die <= get_time())
		{
			check_if_dead(philo);
			return ;
		}
		if (check_dead(philo))
			break ;
		usleep(100);
	}
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_state(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_state(philo, FORK);
	print_state(philo, EATING);
	philo->tt_die = philo->data->time_die + get_time();
	smart_usleep(philo->data->time_eat, philo);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->data->check_fork);
	philo->left_fork->use = false;
	philo->right_fork->use = false;
	pthread_mutex_unlock(&philo->data->check_fork);
}

void	*life(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->nb & 1)
		smart_usleep(philo->data->time_eat, philo);
	while (!check_dead(philo))
	{
		print_state(philo, THINKING);
		if (!check_dead(philo))
			check_eat(philo);
		if (philo->data->meal == true && philo->nb_meal > 1)
			philo->nb_meal--;
		if (philo->data->meal == true && philo->nb_meal == 0)
			return (NULL);
		if (!check_dead(philo))
			print_state(philo, SLEEP);
		smart_usleep(philo->data->time_sleep, philo);
	}
	return (NULL);
}
