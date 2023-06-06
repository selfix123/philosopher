/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:34:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/06 11:26:19 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void)
{
	printf("trump\n");
}


int	main(int ac, char **av)
{
	pthread_t *t1[100];
	int i;

	for (i = 0 ; i < 100; i++){
		if (pthread_create(&t1[i], NULL, &routine, NULL) != 0)
			return (1);
		printf("The thread %d is cumming to ",  i);
	}
	for (i = 0; i < 100; i++){
		if (pthread_join(&t1[i], NULL) != 0)
			return (2);
		printf("The thread %d wrote trump\n", i);
	}
	return (0);
}
