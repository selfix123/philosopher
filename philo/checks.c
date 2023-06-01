/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:22:29 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/01 15:09:42 by zbeaumon         ###   ########.fr       */
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

void	get_time(t_data *data)
{
	
}

void	check_eat(t_philo *philo)
{
}

void	routine(t_data *data)
{
}
