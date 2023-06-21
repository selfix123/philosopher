/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/21 14:15:41 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_data(av, &data);
	if (args_checker(ac, av, &data))
		return (1);
	if (mutex_init(&data))
		return (free(&data), 1);
	if (init_philo(&data))
		return (free(&data), 1);
	if (create_philo(&data))
		return (free(&data), 1);
	if (stop_philo(&data))
		return (1);
	if (destroy_mutex(&data))
		return (1);
	free (&data);
	return (0);
}
