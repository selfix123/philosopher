/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:23:45 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/13 16:56:39 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(char **av, t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->nb_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		data->nb_meal = ft_atoi(av[5]);
		data->meal = true;
	}
	else
		data->meal = false;
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->nb_philo);
	while (i < data->nb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].nb = i + 1;
		data->philo[i].tt_die = data->time_die;
		data->philo[i].nb_meal = data->nb_meal;
		data->philo[i].died = false;
		if (i == 0)
			data->philo[i].left_fork = &data->fork[data->nb_philo - 1];
		else
			data->philo[i].left_fork = &data->fork[i - 1];
		data->philo[i].right_fork = &data->fork[i];
		i++;
	}
	return (0);
}

int	create_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].thread
				, NULL, life, &data->philo[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	stop_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
