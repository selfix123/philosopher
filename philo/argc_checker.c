/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argc_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:43:34 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/05/31 14:52:04 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_checker(int ac, char **av, t_data *data)
{
	if (is_int(ac, av))
		return (1);
	else if (ac != 4)
		return (1);
	else if (data->meal && ac != 5)
		return (1);
	return (0);
}