/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ressalhi <ressalhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:56:31 by ressalhi          #+#    #+#             */
/*   Updated: 2022/05/23 16:29:18 by ressalhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ERROR -3

typedef struct s_philo
{
	int				index;
	int				leftf;
	int				rightf;
	long int		start_time;
	long int		last_meal;
	int				num_time_eat;
	pthread_t		th;
	struct s_data	*d;
}		t_philo;

typedef struct s_data
{
	int				number_of_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				death;
	int				num_philo_eat;
	pthread_t		die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_philo			*philo;
}		t_data;

int			check_if_degit(char *str);
int			ft_atoi(const char *str);
int			parse(t_data *data, int ac, char **av);
int			init_philo_forks(t_data *data);
long int	lw9ita(void);
void		print(t_data *data, long time, int i, char *str);
void		eat(t_philo *philo);
void		n3ass(t_philo *philo);
void		think(t_philo *philo);
int			check_eat(t_data *data);
void		check_death(t_data	*data);
void		*routine(void *arg);

#endif
