/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:44:02 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/24 13:29:16 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		kill(data->philo[i].pid, SIGKILL);
		i++;
	}
}

int	processe_create(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = lw9ita();
	while (i < data->number_of_philo)
	{
		data->philo[i].pid = fork();
		data->philo[i].last_meal = lw9ita();
		if (data->philo[i].pid == 0)
		{
			if (pthread_create(&data->philo[i].die, NULL, &check_death,
					&data->philo[i]) != 0)
				return (0);
			routine(&data->philo[i]);
		}
		usleep(100);
		i++;
	}
	return (1);
}

int	start_processe(t_data *data)
{
	int	i;

	if (!processe_create(data))
		return (0);
	i = 0;
	while (i < data->number_of_philo)
	{
		waitpid(-1, 0, 0);
		kill_all(data);
		i++;
	}
	return (1);
}

int	error_management(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error Bad Arguments\n");
		return (0);
	}
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
	data->philo = malloc(sizeof(t_philo) * (data->number_of_philo));
	if (!data->philo)
		return (0);
	init(data);
	if (!start_processe(data))
		return (0);
}
