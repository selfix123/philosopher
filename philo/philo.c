/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/12 13:45:26 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data(av, data);
	if (!args_checker(ac, av, data))
		return (1);
	if (!mutex_init(data))
		return (free(data), 1);
	if (!init_philo(data))
		return (free(data), 1);
	if (!create_philo(data))
		return (free(data), 1);
	if (stop_philo(data))
		return (1);
	if (destroy_mutex(data))
		return (1);
	return (0);
}
