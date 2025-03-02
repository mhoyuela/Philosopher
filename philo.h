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

# define YELLOW "\033[0;93m"
# define BLUE "\033[0;96m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RED "\033[0;31m"
# define WHITE "\033[37;1m"

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
	pthread_mutex_t	monitor_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philos		philos;
}					t_data;

typedef struct s_philos
{
	pthread_t		thread;
	pthread_mutex_t	*fork_1;
	pthread_mutex_t	*fork_2;
	pthread_mutex_t	count_eat_lock;
	pthread_mutex_t	last_time_to_eat_lock;
	pthread_mutex_t	philo_full_lock;
	size_t			first_meal;
	long			last_time_to_eat;
	long			count_eat;
	int				times_eaten;
	int				n_time_to_eat;
	int				philo_full;
	int				id;
	t_data			*data;
}				t_philos;

//init

void	init_forks(pthread_mutex_t *forks, int n_philos);
void	init_philo(t_philos *philos, t_data *data, phtread_mutex_t *forks, char **argv);
void	init_program(t_philos *philos, t_data *data, char **argv);
void	init_threads(t_data *data, phtread_mutex_t *forks, t_philos *philos);


//utils

void	ft_error(char *str);
long	ft_atoi(char *str);
size_t	ft_get_time(void)

//prints

void    ft_print(char *str, t_philos *philos, int id);

#endif