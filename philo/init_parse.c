/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:02:06 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/23 16:26:39 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	lw9ita(void)
{
	long int		time;
	struct timeval	c_time;

	gettimeofday(&c_time, NULL);
	time = ((c_time.tv_sec * 1000) + (c_time.tv_usec / 1000));
	return (time);
}

int	parse(t_data *data, int ac, char **av)
{
	data->number_of_philo = ft_atoi(av[1]);
	if (data->number_of_philo == ERROR || data->number_of_philo == 0)
		return (0);
	data->time_die = ft_atoi(av[2]);
	if (data->time_die == ERROR)
		return (0);
	data->time_eat = ft_atoi(av[3]);
	if (data->time_eat == ERROR)
		return (0);
	data->time_sleep = ft_atoi(av[4]);
	if (data->time_sleep == ERROR)
		return (0);
	data->num_philo_eat = -1;
	if (ac == 6)
	{
		data->num_philo_eat = ft_atoi(av[5]);
		if (data->num_philo_eat == 0)
			return (0);
	}
	data->death = 1;
	return (1);
}

int	init_philo_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].d = data;
		data->philo[i].index = i + 1;
		data->philo[i].leftf = i;
		data->philo[i].rightf = (i + 1) % data->number_of_philo;
		data->philo[i].last_meal = 0;
		data->philo[i].num_time_eat = 0;
		i++;
	}
	i = 0;
	while (i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_eat(t_data *data)
{
	if (data->philo[data->number_of_philo - 1].num_time_eat
		== data->num_philo_eat)
	{
		data->death = 0;
		usleep(300 * 1000);
		return (0);
	}
	return (1);
}
