/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:02:25 by heom              #+#    #+#             */
/*   Updated: 2021/11/26 04:22:33 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *watch_philo_died(void *philo)
{
    t_philo		*now_philo;
	uint64_t	time_die;
	
	now_philo = (t_philo *)philo;
	time_die = (uint64_t)all()->time_die;
	while (get_time() - now_philo->eat_start < time_die)
		usleep(50);
	if (all()->philo_state != PHILO_DIED)
	{
		printf("타임아웃죽음---------------\n");
		pthread_mutex_lock(&all()->state);
		philo_die(now_philo);
		pthread_mutex_lock(&all()->state);
		return ((void *)1);
	}
	return ((void *)0);
}

int		all_philo_fulfilled(t_philo *philo)
{
	if (philo->must_eat == 0)
		all()->fulfilled_philo_count++;
	if (all()->fulfilled_philo_count == all()->philo_num)
	{
		pthread_mutex_lock(&all()->state);
		all()->philo_state = PHILO_DIED;
		printf("pp------%d번 선수 퇴장 ----\n", philo->num + 1);
		pthread_mutex_lock(&all()->state);
		return (1);
	}
	return (0);
}

void *philo_routine(void *philo)
{
    t_philo *now_philo;
    
	now_philo = (t_philo *)philo;
	if(pthread_create(&now_philo->monitor, NULL, &watch_philo_died, philo))
	{
		printf("------모니터 선수 에러 ----\n");
		return ((void *)ERR);
	}
	pthread_detach(now_philo->monitor);
	while(1)
	{
		if (philo_eat(now_philo))
		{
			printf("bb------%d번 선수 퇴장 ----\n", now_philo->num + 1);
			return ((void *)1);
		}
		if (all_philo_fulfilled(now_philo))
		{
			printf("aa------%d번 선수 퇴장 ----\n", now_philo->num + 1);
			return ((void *)1);
		}
		if (philo_sleep(now_philo))
		{
			printf("cc------%d번 선수 퇴장 ----\n", now_philo->num + 1);
			return ((void *)1);
		}
		if (philo_think(now_philo))
		{
			printf("dd------%d번 선수 퇴장 ----\n", now_philo->num + 1);
			return ((void *)1);
		}
		if (all()->philo_state == PHILO_DIED)
		{
			printf("ee------%d번 선수 퇴장 ----\n", now_philo->num + 1);
			return ((void *)1);
		}
	}
	printf("ff------%d번 선수 퇴장 ----\n", now_philo->num);
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
        res = pthread_create(&all()->philo[i].thread_id, NULL, &philo_routine, now_philo);
        i += 2;
    }
    return (res);
}

int	one_philo_logic(void)
{
	if (!usleep_loop(all()->time_die))
		print_fuc(all()->philo, PRINT_DIE);
	return (0);
}

int lifecycle_thread_philo(void)
{
    int res;
    int i;

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