/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:43:34 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/13 17:04:41 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_checker(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	if (data->meal == true && ac < 5)
		return (printf("Need at least 4 arguments\n"));
	else if (data->meal == true && ac != 6)
		return (printf("need 5 arguments\n"));
	else if (ft_atoi(av[1]) > 200)
		return (printf("Too much philo, try below 200\n"));
	while (++i < ac)
	{
		if (!is_int(ac, av))
			return (printf("All arguments must be integer"), 1);
	}
	return (0);
}
