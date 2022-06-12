/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:57:43 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/23 22:51:48 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->d->forks[philo->leftf]);
	print(philo->d, philo->start_time, philo->index, "has taken left fork");
	pthread_mutex_lock(&philo->d->forks[philo->rightf]);
	print(philo->d, philo->start_time, philo->index, "has taken right fork");
	print(philo->d, philo->start_time, philo->index, "is eating");
	philo->last_meal = lw9ita();
	usleep(philo->d->time_eat * 500);
	while (lw9ita() - philo->last_meal < philo->d->time_eat)
		usleep(300);
	philo->num_time_eat++;
	pthread_mutex_unlock(&philo->d->forks[philo->leftf]);
	pthread_mutex_unlock(&philo->d->forks[philo->rightf]);
	return ;
}

void	n3ass(t_philo *philo)
{
	long	time;

	print(philo->d, philo->start_time, philo->index, "is sleeping");
	time = lw9ita();
	usleep(philo->d->time_sleep * 500);
	while (lw9ita() - time < philo->d->time_sleep)
		usleep(300);
	return ;
}

void	think(t_philo *philo)
{
	print(philo->d, philo->start_time, philo->index, "is thinking");
	return ;
}

void	check_death(t_data	*data)
{
	int			i;
	long int	time;

	while (1)
	{
		i = 0;
		while (i < data->number_of_philo && data->death)
		{
			time = lw9ita() - data->philo[i].last_meal;
			if (time >= data->time_die)
			{
				data->death = 0;
				pthread_mutex_lock(&data->print);
				printf("%ld ms %d died\n", lw9ita() - data->philo[i].start_time,
					data->philo[i].index);
				usleep(300 * 1000);
				return ;
			}
			if (!check_eat(data))
				return ;
			i++;
		}
		usleep(100);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = lw9ita();
	while (philo->d->death)
	{
		if (!philo->d->death)
			break ;
		eat(philo);
		if (!philo->d->death)
			break ;
		n3ass(philo);
		if (!philo->d->death)
			break ;
		think(philo);
		usleep(100);
	}
	return (0);
}
