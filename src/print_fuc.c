/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fuc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eomhyeonjun <eomhyeonjun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:04:05 by eomhyeonjun       #+#    #+#             */
/*   Updated: 2021/11/24 06:27:38 by eomhyeonjun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_color(int type)
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

void    print_msg(t_philo *philo, int type)
{
    uint64_t    time;

    time = get_time() - all()->start_time;
    if (type == PRINT_EAT)
	    printf("%llums %d is eating\n", time, philo->num);
    else if (type == PRINT_GRAP_FORK)
	    printf("%llums %d has taken a fork\n", time, philo->num);
    else if (type == PRINT_SLEEP)
	    printf("%llums %d is sleeping\n", time, philo->num);
    else if (type == PRINT_THINK)
	    printf("%llums %d is thinking\n", time, philo->num);
    else if (type == PRINT_DIE)
        printf("%llums %d died\n", time, philo->num);
	printf(ANSI_COLOR_RESET);
}

void    print_fuc(t_philo *philo, int type)
{
    pthread_mutex_lock(&all()->print);
    print_color(type);
    print_msg(philo, type);
    pthread_mutex_unlock(&all()->print);
}