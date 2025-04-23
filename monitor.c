/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 11:29:53 by mhoyuela          #+#    #+#             */
/*   Updated: 2025-03-03 11:29:53 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_die(t_philos *philos, t_data *data)
{
	pthread_mutex_lock(&philos->data->monitor_lock);
	if (ft_get_time() - philos->last_meal >= data->time_to_die)
	{
		ft_print("philos died", philos, philos->id, RED);
		pthread_mutex_unlock(&philos->data->monitor_lock);
		return (1);
	}
	pthread_mutex_unlock(&philos->data->monitor_lock);
	return (0);
}

int	ft_mealcounter(t_philos *philos, t_data *data)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	if (data->n_time_to_eat == -1)
		return (0);
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&philos->data->monitor_lock);
		if (philos[i].times_eaten >= data->n_time_to_eat)
			counter++;
		pthread_mutex_unlock(&philos->data->monitor_lock);
		if (counter == data->n_philos)
			return (1);
		i++;
	}
	return (0);
}

void	ft_monitor(t_data *data, t_philos *philos)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == data->n_philos)
			i = 0;
		if (ft_die(&philos[i], data) || ft_mealcounter(philos, data))
		{
			pthread_mutex_lock(&philos->data->monitor_lock);
			data->dead_flag = 1;
			pthread_mutex_unlock(&philos->data->monitor_lock);
			break ;
		}
		i++;
	}
}
