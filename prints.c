/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 11:29:04 by mhoyuela          #+#    #+#             */
/*   Updated: 2025-03-03 11:29:04 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_print(char *str, t_philos *philos, int id)
{
    size_t  time;

    time = ft_get_time() - philos->first_meal;
    pthread_mutex_lock(&philos->data->write_lock);
    if (!philos->data->dead_flag)
        printf("%zu %d %s\n", time, id, str);
    pthread_mutex_unlock(&philos->data->write_lock);
}

void release_forks(t_philos *philos)
{
    pthread_mutex_unlock(philos->fork_1);  // Liberar tenedor izquierdo
    pthread_mutex_unlock(philos->fork_2);  // Liberar tenedor derecho
}
int	ft_usleep(size_t milisec)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < milisec)
		usleep(10);
	return (0);
}