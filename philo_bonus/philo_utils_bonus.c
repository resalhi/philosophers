/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:38:19 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/24 13:22:54 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

// int    ft_error(char *str)
// {
//     printf("%s", str);
//     exit (0);
// }

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

long int	lw9ita(void)
{
	long int		time;
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	time = ((c_time.tv_sec * 1000) + (c_time.tv_usec / 1000));
	return (time);
}

void	print(t_data *data, long time, int i, char *str)
{
	sem_wait(data->print);
	printf("%ld ms %d %s\n", time, i, str);
	sem_post(data->print);
}
