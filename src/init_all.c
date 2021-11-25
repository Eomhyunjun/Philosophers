/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 05:16:35 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/26 04:27:50 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parsing_arg(int argc, char **argv)
{
    if (argc == 5 || argc == 6)
    {
        all()->philo_num = ft_atoi(argv[1]);
        all()->time_die = ft_atoi(argv[2]);
        all()->time_eat = ft_atoi(argv[3]);
        all()->time_sleep = ft_atoi(argv[4]);
        all()->must_eat = -1;
        if (argc == 6)
            all()->must_eat = ft_atoi(argv[5]); 
    }
    else
        return (ERR);
    return (SUCCES);
}

int init_mutex(void)
{
    int i;
    int res;

    res = 0;
	if (pthread_mutex_init(&all()->print, NULL))
		return (ERR);
    if (pthread_mutex_init(&all()->state, NULL))
		return (ERR);
    i = 0;
    while (!res && i < all()->philo_num)
    {
        printf("fork : %d\n", i);
        res = pthread_mutex_init(&all()->forks[i], NULL);
        i++;
    }
    return (res);
}

int init_all(int argc, char **argv)
{
	if (parsing_arg(argc, argv))
        return (ERR);        
    all()->philo_state = PHILO_ALIVE;
    all()->start_time = get_time();
    all()->fulfilled_philo_count = 0;
    all()->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all()->philo_num);
    if (!all()->forks)
        return (ERR);
    if (init_mutex())
        return (ERR);
    all()->philo = (t_philo *)malloc(sizeof(t_philo) * (all()->philo_num));
    if (!all()->philo)
        return (ERR);    
    printf("philo_num : %d\n", all()->philo_num);
    printf("time_die : %d\n", all()->time_die);
    printf("time_eat : %d\n", all()->time_eat);
    printf("time_sleep : %d\n", all()->time_sleep);
    printf("must_eat : %d\n", all()->must_eat);
	return (SUCCES);
}

// printf("----인자 확인------\n");
// printf("philo_num : %d\n", all()->philo_num);
// printf("time_die : %d\n", all()->time_die);
// printf("time_eat : %d\n", all()->time_eat);
// printf("time_sleep : %d\n", all()->time_sleep);
// printf("must_eat : %d\n", all()->must_eat);