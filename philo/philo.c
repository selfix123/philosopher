/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/22 12:07:57 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*xfree(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	free_all(t_data *data)
{
	xfree(data->philo);
	xfree(data->fork);
}

int	main(int ac, char **av)
{
	t_data	data;

	init_data(av, &data);
	if (args_checker(ac, av, &data))
		return (1);
	if (mutex_init(&data))
		return (free_all(&data), 1);
	if (init_philo(&data))
		return (free_all(&data), 1);
	if (create_philo(&data))
		return (free_all(&data), 1);
	if (stop_philo(&data))
		return (free_all(&data), 1);
	if (destroy_mutex(&data))
		return (free_all(&data), 1);
	free_all(&data);
}
