/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 15:05:03 by mhoyuela          #+#    #+#             */
/*   Updated: 2025-02-10 15:05:03 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_threads(t_data *data, pthread_mutex_t *forks, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		usleep(5000);
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
			ft_destroy(data, forks);
		i++;
	}
	ft_monitor(data, philos);
	i = 0;
	while (i < data->n_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			ft_destroy(data, forks);
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int n_philos)
{
	int	i;

	i = 0;
	while (i < n_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philo(t_philos *philos, t_data *data, pthread_mutex_t *forks, char **argv)
{
	int i;

	i = 0;
	while (i < data->n_philos)
	{
		data[i].time_to_die = ft_atoi(argv[2]);
		data[i].time_to_eat = ft_atoi(argv[3]);
		data[i].time_to_sleep = ft_atoi(argv[4]);
		philos[i].last_meal = ft_get_time();
		philos[i].id = i + 1;
		philos[i].fork_1 = &forks[i];
		if (philos[i].id == 1)
			philos[i].fork_2 = &forks[data->n_philos - 1];
		else
			philos[i].fork_2 = &forks[data->n_philos - 1];
		philos[i].first_meal = ft_get_time();
		philos[i].times_eaten = 0;
		if (argv[5])
			philos[i].n_time_to_eat = ft_atoi(argv[5]);
		else
			philos[i].n_time_to_eat = ft_atoi(argv[5]);
		philos[i].data = data;
		i++;
	}
}

void	init_program(t_philos *philos, t_data *data, char **argv)
{
	pthread_mutex_t forks[200];

	data->n_philos = ft_atoi(argv[1]);
	data->dead_flag = 0;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	init_forks(forks, data->n_philos);
	init_philo(philos, data, forks, argv);
	data->philos = philos;
	if (data->n_philos == 1)
	{
		ft_print("has taken a fork", philos, philos->id);
		usleep(ft_atoi(argv[2]) * 1000);
		ft_print("died", philos, philos->id);
		return ;
	}
	init_threads(data, forks, philos);
}

