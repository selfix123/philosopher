/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:17:01 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/06/25 13:30:27 by zbeaumon         ###   ########.fr       */
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

int	is_int(char *av)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(av);
	while (++i < len)
		if (!ft_isdigit(av[i]))
			return (0);
	if (len > 10)
		return (0);
	else if (len == 10 && ft_liatoi(av) > INT_MAX)
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
