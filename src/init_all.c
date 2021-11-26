/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 05:16:35 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/26 17:01:29 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int
	arg_vaild_chk(int argc, char **argv)
{
	int	res;
	int	i;

	res = 0;
	i = 1;
	if (argc < 5 || argc > 6)
		return (ARG_NUM_ERR);
	while (!res && i < argc)
	{
		res = char_is_num(argv[i]);
		i++;
	}
	if (res == 1)
		return (ARG_IS_NOT_INT);
	if (ft_atoi(argv[1]) > 200)
		return (TOO_MANY_PHILO);
	if (ft_atoi(argv[2]) < 60)
		return (MORE_THAN_60);
	if (ft_atoi(argv[3]) < 60)
		return (MORE_THAN_60);
	if (ft_atoi(argv[4]) < 60)
		return (MORE_THAN_60);
	return (SUCCES);
}

void
	parsing_arg(int argc, char **argv)
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
}

int
	init_mutex(void)
{
	int	i;
	int	res;

	res = 0;
	if (pthread_mutex_init(&all()->print, NULL))
		return (MUTEX_INIT_ERR);
	if (pthread_mutex_init(&all()->state, NULL))
		return (MUTEX_INIT_ERR);
	i = 0;
	while (!res && i < all()->philo_num)
	{
		res = pthread_mutex_init(&all()->forks[i], NULL);
		i++;
	}
	return (res);
}

int
	init_all(int argc, char **argv)
{
	int	res;

	res = arg_vaild_chk(argc, argv);
	if (res)
		return (res);
	parsing_arg(argc, argv);
	all()->philo_state = PHILO_ALIVE;
	all()->start_time = get_time();
	all()->fulfilled_philo_count = 0;
	all()->forks = malloc(sizeof(pthread_mutex_t) * all()->philo_num);
	if (!all()->forks)
		return (MALLOCK_ERR);
	if (init_mutex())
		return (MUTEX_INIT_ERR);
	all()->philo = (t_philo *)malloc(sizeof(t_philo) * (all()->philo_num));
	if (!all()->philo)
		return (MALLOCK_ERR);
	return (SUCCES);
}
