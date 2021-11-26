/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_philo_died.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:51:37 by heom              #+#    #+#             */
/*   Updated: 2021/11/26 16:42:26 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	philo_die(t_philo *philo)
{
	all()->philo_state = PHILO_DIED;
	print_fuc(philo, PRINT_DIE);
	return (0);
}

void
	*watch_philo_died(void *philo)
{
	t_philo		*now_philo;
	uint64_t	time_die;

	now_philo = (t_philo *)philo;
	time_die = (uint64_t)all()->time_die;
	while (get_time() - now_philo->eat_start < time_die)
		usleep(50);
	if (all()->philo_state != PHILO_DIED)
	{
		pthread_mutex_lock(&all()->state);
		philo_die(now_philo);
		pthread_mutex_lock(&all()->state);
		return ((void *)1);
	}
	return ((void *)0);
}
