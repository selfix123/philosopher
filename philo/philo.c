/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/31 15:25:13 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(int ac, char **av, t_data *data)
{
	data->nb_philo = av[1];
	data->time_dead = av[2];
	data->time_eat = av[3];
	data->time_sleep = av[4];
	if (av[5])		
	{
		data->nb_meal = av[5];
		data->meal = true;
	}
}

void	create_philo(t_philo *philo)
{
	pthread_create()
}

int	main(int ac, char **av)
{
	t_data	*data;

	args_checker(ac, av, &data);
	init_philo(ac, av, &data);
}
