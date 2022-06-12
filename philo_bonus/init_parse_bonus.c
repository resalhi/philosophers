/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:38:21 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/24 14:05:35 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philo[i].d = data;
		data->philo[i].index = i + 1;
		data->philo[i].last_meal = 0;
		data->philo[i].num_time_eat = 0;
		i++;
	}
	sem_unlink("forks");
	data->forks = sem_open("forks", O_CREAT, 0644, data->number_of_philo);
	sem_unlink("print");
	data->print = sem_open("print", O_CREAT, 0644, 1);
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
