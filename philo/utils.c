/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:17:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/21 14:18:55 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

void	ft_bzero(void *str, size_t n)
{
	if (!str)
		return ;
	memset(str, 0, n);
}

int	is_int(int ac, char **av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(av[i]);
	while (len < ac)
		if (ft_isdigit(av[i++][j++]))
			return (0);
	if (len > 11)
		return (0);
	else if (len == 11 && ft_liatoi(av[i]) < INT_MIN)
		return (0);
	else if (len == 10 && ft_liatoi(av[i]) > INT_MAX)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	count;
	int	res;

	count = 1;
	res = 0;
	if (!str)
		return (0);
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		count = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (count * res);
}
