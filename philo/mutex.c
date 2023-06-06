/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:44:23 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/06 12:41:56 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		reutrn (1);
	while (i > 0)
	{
		if (pthread_mutex_init(&data->fork->mutex, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->check_fork, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->print, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->check_fork, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		reutrn (1);
	while (i > 0)
	{
		if (pthread_mutex_destroy(&data->fork->mutex) != 0)
			return (1);
		if (pthread_mutex_destroy(&data->check_fork) != 0)
			return (1);
		if (pthread_mutex_destroy(&data->print) != 0)
			return (1);
		if (pthread_mutex_destroy(&data->check_fork) != 0)
			return (1);
		i++;
	}
	return (0);
}
