/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyuela <mhoyuela@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 14:08:39 by mhoyuela          #+#    #+#             */
/*   Updated: 2025-02-10 14:08:39 by mhoyuela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_philos		philos;
	t_data			data;
	pthread_mutex_t	*forks;

	if (argc != 5 && argc != 6)
		return (printf("ERROR: Number of arguments"));
	if (check_arg(argv))
		return (1);
}
