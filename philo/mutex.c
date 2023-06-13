/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:44:23 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/13 14:14:28 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	data->fork = malloc(sizeof(t_fork) * data->nb_philo);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork->mutex, NULL) != 0)
			return (1);
		data->fork[i].use = false;
		i++;
	}
	pthread_mutex_init(&data->check_fork, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->die, NULL);
	return (0);
}

int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_destroy(&data->fork->mutex) != 0)
			return (1);
		free(data->fork);
		i++;
	}
	pthread_mutex_destroy(&data->check_fork);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->die);
	return (0);
}
