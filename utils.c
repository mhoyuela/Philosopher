/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 11:37:15 by mhoyuela          #+#    #+#             */
/*   Updated: 2025-02-11 11:37:15 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long ft_atoi(char *str)
{
	long	result;
	int		i;
	int		sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		else
			return (-1);
	}
	return (result * sign);
}

int	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
	return (1);
}

size_t	ft_get_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/*Esta funcion calcula el timepo en milisegundos, con una paranoia
muy rara y muy absurda*/

void	ft_destroy(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		phtread_mutex_destroy(&forks[i]);
		i++;
	}
	phtread_mutex_destroy(&data->monitor_lock);
}

int	ft_loop(t_philos *philos)
{
	pthread_mutex_lock(&philos->data->write_lock);
	if (philos->data->dead_flag)
	{
		pthread_mutex_unlock(&philos->data->write_lock);
		return (1);
	}
	pthread_mutex_unlock(&philos->data->write_lock);
	return (0);
}