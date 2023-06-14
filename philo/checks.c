/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:22:29 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/14 18:33:31 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print);
	if (!philo->data->died || (philo->data->died && philo->died))
		printf("%lld %d %s\n", get_time(), philo->nb, message);
	pthread_mutex_unlock(&philo->data->print);
}

void	check_if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die);
	if (philo->tt_die <= get_time() && !philo->data->died)
	{
		philo->died = true;
		philo->data->died = true;
		philo->temp = 1;
		print_state(philo, DIED);
	}
	pthread_mutex_unlock(&philo->data->die);
}

int	check_forks(t_philo *philo)
{
	int	use;

	use = 0;
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
	while (!check_forks(philo) && philo->temp == 0)
	{
		usleep(100);
		if (philo->died == true || philo->temp == 0)
		{
			check_if_dead(philo);
			return ;
		}
	}
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_state(philo, FORK);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_state(philo, FORK);
	print_state(philo, EATING);
	smart_usleep(philo->data->time_eat, philo);
	philo->tt_die = philo->data->time_die + get_time();
	pthread_mutex_unlock(&philo->left_fork->mutex);
	printf("%p\n", &philo->right_fork->mutex);
	philo->left_fork->use = false;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	philo->right_fork->use = false;
}

void	*life(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->nb & 1)
		smart_usleep(philo->data->time_eat, philo);
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
		smart_usleep(philo->data->time_sleep, philo);
	}
	return (NULL);
}
