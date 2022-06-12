/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:41:38 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/23 21:50:15 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_degit(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] > 57 || str[i] < 48)
			return (0);
		i++;
		count++;
	}
	if (count >= 11)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int				j;
	long long int	k;

	j = 1;
	k = 0;
	while ((*str <= 13 && *str >= 9) || *str == ' ')
		str++;
	if (*str == '-')
		j *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		k = k * 10 + *str - 48;
		str++;
	}
	k = k * j;
	if (k >= 2147483647)
		return (ERROR);
	if (k <= -2147483648)
		return (ERROR);
	return (k);
}

void	print(t_data *data, long time, int i, char *str)
{
	pthread_mutex_lock(&data->print);
	printf("%ld ms %d %s\n", lw9ita() - time, i, str);
	pthread_mutex_unlock(&data->print);
}
