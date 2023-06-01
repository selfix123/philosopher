/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:52:41 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/01 11:56:32 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_int(int ac, char **av)
{
	int	i;
	int	len;

	i = -1;
	while (++i < ac)
	{
		len = ft_strlen(av[i]);
		if (len > 11)
			return (1);
		if (len == 11 && ft_liatoi(av[i]) < INT_MIN)
			return (1);
		if (len == 10 && ft_liatoi(av[i]) > INT_MAX)
			return (1);
	}
	return (0);
}
