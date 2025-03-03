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
    phtread_mutex_lock(&philos->data->write_lock);
    if (!philos->data->dead_flag)
        printf("%d %s\n", time, id, str);
    phtread_mutex_unlock(&philos->data->write_lock);
}