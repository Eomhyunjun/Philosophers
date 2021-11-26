/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:02:25 by heom              #+#    #+#             */
/*   Updated: 2021/11/26 15:52:01 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	*philo_routine(void *philo)
{
	t_philo	*now_philo;

	now_philo = (t_philo *)philo;
	if (pthread_create(&now_philo->monitor, NULL, &watch_philo_died, philo))
	{
		printf("------모니터 선수 에러 ----\n");
		return ((void *)ERR);
	}
	pthread_detach(now_philo->monitor);
	while (1)
	{
		if (philo_eat(now_philo))
			return ((void *)1);
		if (all_philo_fulfilled(now_philo))
			return ((void *)1);
		if (philo_sleep(now_philo))
			return ((void *)1);
		if (philo_think(now_philo))
			return ((void *)1);
		if (all()->philo_state == PHILO_DIED)
			return ((void *)1);
	}
	return ((void *)0);
}

int
	create_thread(int odd)
{
	void	*now_philo;
	int		i;
	int		res;

	res = 0;
	i = odd;
	if (odd == EVEN && all()->philo_num < 100)
		usleep(100);
	else if (odd == EVEN)
		usleep(200);
	while (!res && i < all()->philo_num)
	{
		all()->philo[i].num = i;
		now_philo = &(all()->philo[i]);
		res = pthread_create(&all()->philo[i].thread_id, NULL, \
								&philo_routine, now_philo);
		i += 2;
	}
	return (res);
}

int
	one_philo_logic(void)
{
	if (!usleep_loop(all()->time_die))
		print_fuc(all()->philo, PRINT_DIE);
	return (0);
}

int
	lifecycle_thread_philo(void)
{
	int	res;
	int	i;

	if (all()->philo_num == 1)
		return (one_philo_logic());
	res = create_thread(ODD);
	if (!res)
		res = create_thread(EVEN);
	i = 0;
	while (!res && i < all()->philo_num)
	{
		res = pthread_join(all()->philo[i].thread_id, NULL);
		i++;
	}
	return (res);
}
