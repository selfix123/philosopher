/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/02 13:42:39 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	printf("trump\n");
}

void	*routine23()
{
	printf("poutine\n");
}

int	main(int ac, char **av)
{
	pthread_t *t1, t2, t3, t4;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		pthread_create(&t1, NULL, &routine, NULL);
		pthread_create(&t2, NULL, &routine, NULL);
		pthread_create(&t3, NULL, &routine23, NULL);
		pthread_create(&t4, NULL, &routine23, NULL);
		i++;	
	}
	while (j < 100)
	{
		pthread_join(&t1, NULL);
		pthread_join(&t2, NULL);
		pthread_join(&t3, NULL);
		pthread_join(&t4, NULL);
		j++;
	}
	return (0);
}
