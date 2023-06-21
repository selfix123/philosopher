/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:43:34 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/21 11:44:59 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_checker(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	if (ac < 5)
		return (printf("Need at least 4 arguments\n"), 1);
	else if (data->meal == true && ac != 6)
		return (printf("need 5 arguments\n"), 1);
	else if (ft_atoi(av[1]) > 200)
		return (printf("Too much philo, try below 200\n"), 1);
	if (!is_int(ac, av))
		return (write (1, "Not an int\n", 12), 1);
	return (0);
}
