/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:55:05 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/23 18:26:47 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->d->forks);
	print(philo->d, lw9ita() - philo->d->start_time,
		philo->index, "has taken left fork");
	sem_wait(philo->d->forks);
	print(philo->d, lw9ita() - philo->d->start_time,
		philo->index, "has taken right fork");
	print(philo->d, lw9ita() - philo->d->start_time,
		philo->index, "is eating");
	philo->last_meal = lw9ita();
	usleep(philo->d->time_eat * 300);
	while (lw9ita() - philo->last_meal < philo->d->time_eat)
		usleep(300);
	philo->num_time_eat++;
	sem_post(philo->d->forks);
	sem_post(philo->d->forks);
	return ;
}

void	n3ass(t_philo *philo)
{
	long	time;

	print(philo->d, lw9ita() - philo->d->start_time,
		philo->index, "is sleeping");
	time = lw9ita();
	usleep(philo->d->time_sleep * 300);
	while (lw9ita() - time < philo->d->time_sleep)
		usleep(300);
	return ;
}

void	think(t_philo *philo)
{
	print(philo->d, lw9ita() - philo->d->start_time,
		philo->index, "is thinking");
	return ;
}

void	*check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (lw9ita() - philo->last_meal >= philo->d->time_die)
		{
			sem_wait(philo->d->print);
			printf("%ld ms %d died\n", lw9ita() - philo->d->start_time,
				philo->index);
			exit (1);
		}
		usleep(100);
		if (philo->d->philo[philo->d->number_of_philo - 1].num_time_eat
			== philo->d->num_philo_eat)
		{
			philo->d->death = 0;
			return (0);
		}
	}
	return (0);
}

void	routine(t_philo *philo)
{
	while (philo->d->death)
	{
		eat(philo);
		n3ass(philo);
		think(philo);
		usleep(100);
	}
	exit (0);
}
