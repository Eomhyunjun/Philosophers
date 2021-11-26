/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:46:01 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/26 17:02:56 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	print_err(int res)
{
	if (res == 1)
		printf("ARG_NUM_ERR");
	if (res == 2)
		printf("ARG_IS_NOT_INT");
	if (res == 3)
		printf("TOO_MANY_PHILO");
	if (res == 4)
		printf("PHILO_ARC_TIME_MORE_THAN_60");
	if (res == 5)
		printf("MALLOCK_ERR");
	if (res == 6)
		printf("MUTEX_INIT_ERR");
}

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
	free(all()->philo);
}

void
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
}

int
	main(int argc, char **argv)
{
	int	res;

	res = init_all(argc, argv);
	if (res)
		print_err(res);
	if (res == SUCCES)
	{
		init_philo();
		res = lifecycle_thread_philo();
	}
	safe_exit();
	return (0);
}
