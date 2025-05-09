/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 12:04:48 by mhoyuela          #+#    #+#             */
/*   Updated: 2025-03-03 12:04:48 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philos *philos)
{
	if (!philos->fork_1 || !philos->fork_2)
	{
		printf("Null pinter\n");
		return ;
	}
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(philos->fork_2);
		ft_print("has taken a fork", philos, philos->id, ORANGE);
		pthread_mutex_lock(philos->fork_1);
		ft_print("has taken a fork", philos, philos->id, ORANGE);
	}
	else
	{
		pthread_mutex_lock(philos->fork_2);
		ft_print("has taken a fork", philos, philos->id, ORANGE);
		pthread_mutex_lock(philos->fork_1);
		ft_print("has taken a fork", philos, philos->id, ORANGE);
	}
}

void	ft_eat(t_philos *philos)
{
	grab_forks(philos);
	ft_print("is eating", philos, philos->id, GREEN);
	pthread_mutex_lock(&philos->data->monitor_lock);
	philos->last_meal = ft_get_time();
	philos->times_eaten++;
	pthread_mutex_unlock(&philos->data->monitor_lock);
	ft_usleep(philos->data->time_to_eat);
	release_forks(philos);
}

void	ft_sleep(t_philos *philos)
{
	ft_print("is sleeping", philos, philos->id, BLUE);
	ft_usleep(philos->time_to_sleep);
}

void	ft_think(t_philos *philos)
{
	ft_print("is thinking", philos, philos->id, YELLOW);
	ft_usleep (1);
}

void	*routine(void *ptr)
{
	t_philos	*philos;

	philos = (t_philos *)ptr;
	if (philos->id % 2 == 0)
		ft_usleep(10);
	while (!ft_loop(philos))
	{
		ft_eat(philos);
		ft_sleep(philos);
		ft_think(philos);
	}
	return (ptr);
}
