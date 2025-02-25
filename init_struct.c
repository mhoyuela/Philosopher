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

void	init_struct(t_data *data)
{
	data->n_philos = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->num_times_to_eat = 0;
	data->dead_flag = 0;
	data->meals_finish = 0;
	data->time = 0;
	pthread_mutex_init(&data->meal_finish_lock, NULL);
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
}
void	init_philo(t_philos *philos)
{
	
}

int	check_argument(t_data *data, char **argv)
{
	data->n_philos = ft_atoi(argv[1]);
}
