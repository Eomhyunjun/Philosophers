/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:02:25 by heom              #+#    #+#             */
/*   Updated: 2021/11/24 08:51:19 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *watch_philo_died(void *philo)
{
    t_philo		*now_philo;
	uint64_t	time_die;
	
	now_philo = (t_philo *)philo;
	time_die = (uint64_t)all()->time_die;
	while (get_time() - now_philo->eat_end < time_die \
				&& now_philo->must_eat != 0)
		usleep(50);
	pthread_mutex_lock(&all()->state);
	philo_die(now_philo);
	pthread_mutex_lock(&all()->state);
	return ((void *)0);
}

void *philo_routine(void *philo)
{
    t_philo *now_philo;
    
	now_philo = (t_philo *)philo;
	if(pthread_create(&now_philo->monitor, NULL, &watch_philo_died, philo))
		return ((void *)ERR);
	while(1)
	{
		if (all()->philo_state == PHILO_ALIVE)
			philo_eat(now_philo);
		if (all()->philo_state == PHILO_ALIVE)
			philo_sleep(now_philo);
		if (all()->philo_state == PHILO_ALIVE)
			philo_think(now_philo);
		if (all()->philo_state == PHILO_DIED)
			return ((void *)0);
	}
    return ((void *)0);
}

int create_thread(int odd)
{
    void *now_philo;
    int i;
    int res;

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
        // 성공 시 0 리턴
        res = pthread_create(&all()->philo[i].thread_id, NULL, &philo_routine, now_philo);
        i += 2;
    }
    return (res);
}

int lifecycle_thread_philo(void)
{
    int res;
    int i;

    res = create_thread(ODD);
    if (res)
        return (ERR);
    res = create_thread(EVEN);
    if (res)
        return (ERR);
    i = 0;
    while (i < all()->philo_num)
    {
        pthread_join(all()->philo[i].thread_id, NULL);
        i++;
    }
    return (res);
}