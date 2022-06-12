/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:56:18 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/23 22:54:14 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	odd_thread(t_data *data, long time)
{
	int		i;

	i = 1;
	while (i < data->number_of_philo)
	{
		data->philo[i].start_time = time;
		data->philo[i].last_meal = time;
		if (pthread_create(&data->philo[i].th, NULL, &routine,
				(void *)&data->philo[i]) != 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int	even_thread(t_data *data, long time)
{
	int		i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].start_time = time;
		data->philo[i].last_meal = time;
		if (pthread_create(&data->philo[i].th, NULL, &routine,
				(void *)&data->philo[i]) != 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int	create_threads(t_data *data)
{
	long	time;

	time = lw9ita();
	if (!odd_thread(data, time))
		return (0);
	usleep(100);
	if (!even_thread(data, time))
		return (0);
	check_death(data);
	usleep(100);
	return (1);
}

int	error_management(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (0);
	if (!check_if_degit(av[1]) || !check_if_degit(av[2])
		|| !check_if_degit(av[3]) || !check_if_degit(av[4]))
	{
		printf("Error Bad Arguments\n");
		return (0);
	}
	if (ac == 6)
	{
		if (!check_if_degit(av[5]))
		{
			printf("Error Bad Arguments\n");
			return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (!error_management(ac, av))
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (!parse(data, ac, av))
		return (0);
	data->philo = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->philo)
		return (0);
	if (pthread_mutex_init(&data->print, NULL) != 0)
		return (0);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);
	if (!data->forks)
		return (0);
	if (!init_philo_forks(data))
		return (0);
	if (!create_threads(data))
		return (0);
	pthread_mutex_destroy(&data->print);
	return (0);
}
