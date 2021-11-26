/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fuc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:04:05 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/26 15:41:17 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void
	print_color(int type)
{
	if (type == PRINT_EAT)
		printf(ANSI_COLOR_MAGENTA);
	else if (type == PRINT_SLEEP)
		printf(ANSI_COLOR_BLUE);
	else if (type == PRINT_THINK)
		printf(ANSI_COLOR_GREEN);
	else if (type == PRINT_DIE)
		printf(ANSI_COLOR_RED);
}

void	print_msg(t_philo *philo, int type)
{
	uint64_t	time;

	time = get_time() - all()->start_time;
	if (type == PRINT_EAT)
		printf("%llu %d is eating\n", time, philo->num + 1);
	else if (type == PRINT_GRAP_FORK)
		printf("%llu %d has taken a fork\n", time, philo->num + 1);
	else if (type == PRINT_SLEEP)
		printf("%llu %d is sleeping\n", time, philo->num + 1);
	else if (type == PRINT_THINK)
		printf("%llu %d is thinking\n", time, philo->num + 1);
	else if (type == PRINT_DIE)
		printf("%llu %d died\n", time, philo->num + 1);
	printf(ANSI_COLOR_RESET);
}

int	print_fuc(t_philo *philo, int type)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&all()->print);
	if (all()->print_state == CANT_PRINT)
		res = 1;
	if (!res)
	{
		print_color(type);
		print_msg(philo, type);
	}
	if (all()->philo_state == PHILO_DIED)
		all()->print_state = CANT_PRINT;
	pthread_mutex_unlock(&all()->print);
	return (res);
}
