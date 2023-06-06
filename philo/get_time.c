/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:37:57 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/06 12:38:21 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	static struct timeval	current_time = {-1, -1};
	struct timeval			real_time;

	if (current_time.tv_sec == -1 && current_time.tv_usec == -1)
		gettimeofday(&current_time, NULL);
	return ((real_time.tv_sec - current_time.tv_sec * 1000)
		+ real_time.tv_usec - current_time.tv_usec / 1000);
}
