/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 13:37:59 by mhoyuela          #+#    #+#             */
/*   Updated: 2025-02-10 13:37:59 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOFT_H
# define PHILOFT_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define MAX_PHILOS 200

typedef struct s_data
{
	int				n_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			num_times_to_eat;
	int				meals_finish;
	int				dead_flag;
	long			time;
	pthread_mutex_t	meal_finish_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_data;

typedef struct s_philos
{
	pthread_t		thread;
	pthread_mutex_t	*fork_1;
	pthread_mutex_t	*fork_2;
	pthread_mutex_t	count_eat_lock;
	pthread_mutex_t	last_time_to_eat_lock;
	pthread_mutex_t	philo_full_lock;
	long			last_time_to_eat;
	long			count_eat;
	int				philo_full;
	int				id;
	t_data			*data;
}					t_philos;


#endif