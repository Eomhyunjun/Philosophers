/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:01 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/26 15:47:15 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void
	destroy_mutex(pthread_mutex_t mutex)
{
	int	res;

	res = pthread_mutex_destroy(&mutex);
	if (res == EBUSY)
	{
		pthread_mutex_unlock(&mutex);
		res = pthread_mutex_destroy(&mutex);
	}
}

void
	safe_exit(void)
{
	int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		destroy_mutex(all()->forks[i]);
		i++;
	}
	destroy_mutex(all()->print);
	destroy_mutex(all()->state);
	free(all()->forks);
}

int
	init_philo(void)
{
	int	i;

	i = 0;
	while (i < all()->philo_num)
	{
		all()->philo[i].num = i;
		all()->philo[i].eat_start = all()->start_time;
		if (i == 0)
			all()->philo[i].right_fork = all()->philo_num - 1;
		else
			all()->philo[i].right_fork = all()->philo[i].num - 1;
		all()->philo[i].left_fork = all()->philo[i].num;
		all()->philo[i].must_eat = all()->must_eat;
		i++;
	}
	return (SUCCES);
}

int
	main(int argc, char **argv)
{
	int	res;

	res = init_all(argc, argv);
	if (!res)
		res = init_philo();
	if (!res)
		res = lifecycle_thread_philo();
	safe_exit();
	return (0);
}
