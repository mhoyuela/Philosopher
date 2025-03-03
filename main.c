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

int	check_arg(char **argv)
{
	if ((ft_atoi(argv[1]) > 200) || (ft_atoi(argv[1] < 0)))
		return (ft_error("ERROR: Number of philosopher"));
	if (ft_atoi(argv[2] ) <= 0)
		return (ft_error("ERROR: Time to die"));
	if (ft_atoi(argv[3] ) <= 0)
		return (ft_error("ERROR: Time to eat"));
	if (ft_atoi(argv[4]) <= 0)
		return (ft_error("ERROR: time to sleep"));
	if (argv[5])
	{
		if (ft_atoi(argv[5]) <= 0)
			return (ft_error("ERROR: Number og meals"));
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_philos		philos[200];
	t_data			data;

	if (argc != 5 && argc != 6)
		return (ft_error("ERROR: Number of arguments"));
	if (check_arg(argv))
		return (1);
	init_program(&data, philos, argv);
}
