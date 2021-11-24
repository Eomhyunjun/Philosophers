/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:03:13 by heom              #+#    #+#             */
/*   Updated: 2021/11/24 08:34:15 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void grab_forks(t_philo	*philo){
	pthread_mutex_lock(&all()->forks[philo->left_fork]);
	print_fuc(philo, PRINT_GRAP_FORK);
	pthread_mutex_lock(&all()->forks[philo->right_fork]);
	print_fuc(philo, PRINT_GRAP_FORK);
}

int philo_eat(t_philo	*philo){
	grab_forks(philo);
	print_fuc(philo, PRINT_EAT);
	if (usleep_loop(all()->time_eat))
		return (ERR);
	philo->must_eat--;
	philo->eat_start = get_time();
	pthread_mutex_unlock(&all()->forks[philo->left_fork]);
	pthread_mutex_unlock(&all()->forks[philo->right_fork]);
	return (0);
}

int philo_sleep(t_philo *philo){
	int res;

	print_fuc(philo, PRINT_SLEEP);
	res = usleep_loop(all()->time_sleep);
	return (res);
}

int philo_think(t_philo *philo){
	print_fuc(philo, PRINT_THINK);
	return (0);
}

int philo_die(t_philo *philo){
	all()->philo_state = PHILO_DIED;
	print_fuc(philo, PRINT_DIE);
	return (0);
}