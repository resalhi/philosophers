/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:44:41 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/24 13:48:43 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>

# define ERROR -3

typedef struct s_philo
{
	int				index;
	int				pid;
	long int		last_meal;
	int				num_time_eat;
	pthread_t		die;
	struct s_data	*d;
}		t_philo;

typedef struct s_data
{
	int			number_of_philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			num_philo_eat;
	int			death;
	long int	start_time;
	sem_t		*forks;
	sem_t		*print;
	t_philo		*philo;
}		t_data;

int			check_if_degit(char *str);
int			ft_atoi(const char *str);
long int	lw9ita(void);
void		init(t_data *data);
int			parse(t_data *data, int ac, char **av);
void		print(t_data *data, long time, int i, char *str);
void		routine(t_philo *philo);
void		*check_death(void *arg);
void		kill_all(t_data *data);
void		think(t_philo *philo);
void		n3ass(t_philo *philo);
void		eat(t_philo *philo);

#endif
