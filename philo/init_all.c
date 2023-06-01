/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:23:45 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/01 15:23:15 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int ac, char **av, t_data *data)
{
	data->nb_philo = av[1];
	data->time_die = av[2];
	data->time_eat = av[3];
	data->time_sleep = av[4];
	if (av[5])
	{
		data->nb_meal = av[5];
		data->meal = true;
	}
}

void	*init_philo(t_data *data)
{
	int	i;

	i = 0;
	ft_bzero(data->philo, sizeof(t_philo));
	data->philo = malloc(sizeof(t_philo));
	while (i < data->nb_philo)
	{
		data->philo[i].nb = data->nb_philo;
		data->philo[i].tt_die = data->time_die;
		data->philo[i].nb_meal = data->nb_meal;
		data->philo[i].died = false;
		i++;
	}
}

