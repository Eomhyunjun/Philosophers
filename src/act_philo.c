/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:03:13 by heom              #+#    #+#             */
/*   Updated: 2021/11/26 04:14:04 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int grab_forks(t_philo	*philo){
	int res;

	pthread_mutex_lock(&all()->forks[philo->left_fork]);
	res = print_fuc(philo, PRINT_GRAP_FORK);
	pthread_mutex_lock(&all()->forks[philo->right_fork]);
	res = print_fuc(philo, PRINT_GRAP_FORK);
	return (res);
}

int philo_eat(t_philo	*philo){
	int res;
	
	res = grab_forks(philo);
	philo->must_eat--;
	philo->eat_start = get_time();
	if (!res)
		res = print_fuc(philo, PRINT_EAT);
	if (!res)
		usleep_loop(all()->time_eat);
	pthread_mutex_unlock(&all()->forks[philo->left_fork]);
	pthread_mutex_unlock(&all()->forks[philo->right_fork]);
	return (res);
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