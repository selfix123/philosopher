/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:37:57 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/14 17:01:21 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	get_time(void)
{
	static struct timeval	start = {-1, -1};
	struct timeval			real_time;

	if (start.tv_sec == -1 && start.tv_usec == -1)
		gettimeofday(&start, NULL);
	gettimeofday(&real_time, NULL);
	return ((real_time.tv_sec * 1000 - start.tv_sec * 1000)
		+ real_time.tv_usec / 1000 - start.tv_usec / 1000);
}

void	smart_usleep(t_time time, t_philo *philo)
{
	t_time	start;

	start = get_time();
	if (philo->tt_die < time + start && philo->died == false
		&& philo->tt_die > start)
	{
		usleep((philo->tt_die - start) * 1000);
		check_if_dead(philo);
	}
	else
	{
		while (get_time() < time + start)
			usleep(150);
	}
}
